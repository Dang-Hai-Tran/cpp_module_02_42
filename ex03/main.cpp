/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:52:56 by datran            #+#    #+#             */
/*   Updated: 2023/09/26 13:13:18 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void) {
    {
        Point const a = Point(1, 2);
        Point const b = Point(5, 2);
        Point const c = Point(3, 4);
        Point const point = Point(3, 3);
        if (bsp(a, b, c, point))
            std::cout << "Inside triangle" << std::endl;
        else
            std::cout << "Outside triangle" << std::endl;
    }
    {
        Point const a = Point(1, 2);
        Point const b = Point(5, 2);
        Point const c = Point(3, 4);
        Point const point = Point(5, 5);
        if (bsp(a, b, c, point))
            std::cout << "Inside triangle" << std::endl;
        else
            std::cout << "Outside triangle" << std::endl;
    }
    {
        Point const a = Point(1, 2);
        Point const b = Point(5, 2);
        Point const c = Point(3, 4);
        Point const point = Point(4, 3);
        if (bsp(a, b, c, point))
            std::cout << "Inside triangle" << std::endl;
        else
            std::cout << "Outside triangle" << std::endl;
    }
}
