// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#ifndef _INCL_GUARD
#define _INCL_GUARD

#include "CoreMinimal.h"
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
using std::abs;
using std::max;
using std::vector;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct Point
{
    const double x;
    const double y;
    Point(double x_, double y_) : x(x_), y(y_) {}
};

struct Hex
{
    const int q;
    const int r;
    const int s;
    Hex(int q_, int r_, int s_) : q(q_), r(r_), s(s_) {
        if (q + r + s != 0) throw "q + r + s must be 0";
    }
};

struct FractionalHex
{
    const double q;
    const double r;
    const double s;
    FractionalHex(double q_, double r_, double s_) : q(q_), r(r_), s(s_) {
        if (round(q + r + s) != 0) throw "q + r + s must be 0";
    }
};

struct OffsetCoord
{
    const int col;
    const int row;
    OffsetCoord(int col_, int row_) : col(col_), row(row_) {}
};

struct DoubledCoord
{
    const int col;
    const int row;
    DoubledCoord(int col_, int row_) : col(col_), row(row_) {}
};

struct Orientation
{
    const double f0;
    const double f1;
    const double f2;
    const double f3;
    const double b0;
    const double b1;
    const double b2;
    const double b3;
    const double start_angle;
    Orientation(double f0_, double f1_, double f2_, double f3_, double b0_, double b1_, double b2_, double b3_, double start_angle_) : f0(f0_), f1(f1_), f2(f2_), f3(f3_), b0(b0_), b1(b1_), b2(b2_), b3(b3_), start_angle(start_angle_) {}
};


struct Layout
{
    const Orientation orientation;
    const Point size;
    const Point origin;
    Layout(Orientation orientation_, Point size_, Point origin_) : orientation(orientation_), size(size_), origin(origin_) {}
};

enum OrientationDirections {
    SE,
    NE,
    N,
    NW,
    SW,
    S,
};

#endif