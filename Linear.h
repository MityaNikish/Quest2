#pragma once
#include <vector>
#include <algorithm>
#include "Point3D.h"

template <class T>
concept TypePoint = std::is_same_v<T, Point1D<typename T::value_type>> || std::is_same_v<T, Point2D<typename T::value_type>> || std::is_same_v<T, Point3D<typename T::value_type>>;


template <TypePoint Point>
std::vector<std::pair<Point, std::vector<Point>>> searchKNN(const std::vector<Point>& data, size_t number_neighbors)
{
	std::vector<std::pair<Point, std::vector<Point>>> res(data.size(), std::make_pair<Point, std::vector<Point>>(Point{}, std::vector<Point>(number_neighbors)));
	res.shrink_to_fit();

	std::vector<std::pair<double, const Point*>> neighbors(data.size() - 1);
	neighbors.shrink_to_fit();

	int i = 0;
	for (const Point& point_main : data)
	{
		res[i].first = point_main;
		auto neighbor_index = neighbors.begin();
		for (const Point& point_neighbor : data)
		{
			if (&point_main == &point_neighbor)	continue;

			*neighbor_index = std::make_pair<double, const Point*>(distance(point_main, point_neighbor), &point_neighbor);
			++neighbor_index;
		}
		std::ranges::sort(neighbors, {}, [](const std::pair<double, const Point*>& pair) {
			return pair.first;
			});


		for (size_t j = 0; j < number_neighbors && j < neighbors.size(); j++)
		{
			res[i].second[j] = *(neighbors[j].second);
		}
		++i;
	}

	return res;
}


template <TypePoint Point>
std::vector<std::pair<Point, std::vector<Point>>> searchNNInZone(const std::vector<Point>& data, double dist)
{
	std::vector<std::pair<Point, std::vector<Point>>> res(data.size(), std::make_pair<Point, std::vector<Point>>(Point{}, std::vector<Point>{}));
	res.shrink_to_fit();

	std::vector<std::pair<double, const Point*>> neighbors(data.size() - 1);
	neighbors.shrink_to_fit();

	int i = 0;
	for (const Point& point_main : data)
	{
		res[i].first = point_main;
		auto neighbor_index = neighbors.begin();
		for (const Point& point_neighbor : data)
		{
			if (&point_main == &point_neighbor)	continue;

			*neighbor_index = std::make_pair<double, const Point*>(distance(point_main, point_neighbor), &point_neighbor);
			++neighbor_index;
		}
		std::ranges::sort(neighbors, {}, [](const std::pair<double, const Point*>& pair) {
			return pair.first;
			});


		for (size_t j = 0; j < neighbors.size(); j++)
		{
			if (neighbors[j].first > dist)
			{
				break;
			}
			res[i].second.push_back(*(neighbors[j].second));
		}
		++i;
	}

	return res;
}