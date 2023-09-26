/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:15:24 by datran            #+#    #+#             */
/*   Updated: 2023/09/26 13:07:00 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed const areaTriangle(Point const a, Point const b, Point const c) {
    Fixed area =
        Fixed((float)0.5) * ((b.getX() - a.getX()) * (c.getY() - a.getY()) -
                             (b.getY() - a.getY()) * (c.getX() - a.getX()));
    return area >= 0 ? area : (area) * (-1);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed areaABC = areaTriangle(a, b, c);
    Fixed areaAPB = areaTriangle(a, point, b);
    Fixed areaBPC = areaTriangle(b, point, c);
    Fixed areaCPA = areaTriangle(c, point, a);
    return (areaAPB != 0 && areaBPC != 0 && areaCPA != 0 &&
            areaABC == areaAPB + areaBPC + areaCPA);
}
