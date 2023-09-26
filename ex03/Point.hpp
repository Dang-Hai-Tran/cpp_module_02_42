/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:10:53 by datran            #+#    #+#             */
/*   Updated: 2023/09/26 11:16:44 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
  public:
    Point();
    Point(float x, float y);
    Point(Point const &src);
    // Operator overload
    Fixed const getX(void) const;
    Fixed const getY(void) const;
    ~Point();

  private:
    Fixed const x;
    Fixed const y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
