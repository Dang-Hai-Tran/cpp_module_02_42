/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:12:50 by datran            #+#    #+#             */
/*   Updated: 2023/09/26 11:16:39 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float x, float y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(Point const &src) : x(src.x), y(src.y) {}

Fixed const Point::getX(void) const { return x; }

Fixed const Point::getY(void) const { return y; }

Point::~Point() {}
