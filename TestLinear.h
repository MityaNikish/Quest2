#pragma once
#include "Linear.h"
#include <iostream>
#include <cstdlib>
#include <chrono>


template <class Type>
void createPoint(Point1D<Type>& point)
{
    point.setX(std::rand() / 1000);
}

template <class Type>
void createPoint(Point2D<Type>& point)
{
    point.setX(std::rand() / 1000);
    point.setY(std::rand() / 1000);
}

template <class Type>
void createPoint(Point3D<Type>& point)
{
    point.setX(std::rand() / 1000);
    point.setY(std::rand() / 1000);
    point.setZ(std::rand() / 1000);
}


template <class Type>
void printPoint(const Point1D<Type>& point)
{
    std::cout << point.getX();
}

template <class Type>
void printPoint(const Point2D<Type>& point)
{
    std::cout << point.getX() << " " << point.getY();
}

template <class Type>
void printPoint(const Point3D<Type>& point)
{
    std::cout << point.getX() << " " << point.getY() << " " << point.getZ();
}


template <TypePoint Point>
void printKNN(const std::vector<std::pair<Point, std::vector<Point>>>& data)
{
    for (auto& pair : data)
    {
        std::cout << "Point: ";
        printPoint(pair.first);
        std::cout << "\nK nearest neighbor:\n";
        for (auto& point : pair.second)
        {
            std::cout << "\tNeighbor: ";
            printPoint(point);
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}


template <TypePoint Point>
struct TestLinear
{
    static void searchKNN_Vizualization(size_t quantity_point, size_t number_neighbors)
    {
        std::vector<Point> points(quantity_point);
        for (auto& point : points)
        {
            createPoint(point);
            printPoint(point);
            std::cout << "\n";
        }
        std::cout << "\n\n";

        std::vector<std::pair<Point, std::vector<Point>>> res = searchKNN<Point>(points, number_neighbors);
        printKNN(res);
    }

    static void searchKNN_Speed(size_t quantity_point, size_t number_neighbors)
    {
        std::vector<Point> points(quantity_point);
        for (auto& point : points)
        {
            createPoint(point);
        }

        auto begin = std::chrono::steady_clock::now();

        searchKNN<Point>(points, number_neighbors);

        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << "\nLead time: " << elapsed_ms.count() << "ms" << std::endl;
    }

    static void searchNNInZone_Vizualization(size_t quantity_point, double distance)
    {
        {
            std::vector<Point> points(quantity_point);
            for (auto& point : points)
            {
                createPoint(point);
                printPoint(point);
                std::cout << "\n";
            }
            std::cout << "\n\n";

            std::vector<std::pair<Point, std::vector<Point>>> res = searchNNInZone<Point>(points, distance);
            printKNN(res);
        }
    }

    static void searchNNInZone_Speed(size_t quantity_point, double distance)
    {
        std::vector<Point> points(quantity_point);
        for (auto& point : points)
        {
            createPoint(point);
        }

        auto begin = std::chrono::steady_clock::now();

        searchNNInZone<Point>(points, distance);

        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << "\nLead time: " << elapsed_ms.count() << "ms" << std::endl;
    }
};