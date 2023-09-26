/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:19:03 by datran            #+#    #+#             */
/*   Updated: 2023/09/26 11:09:56 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
    std::cout << "Default constructor called" << std::endl;
    this->fixedPointValue = 0;
};

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(int const n) {
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = n << fractionalBits;
}

Fixed::Fixed(float const f) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(f * (1 << Fixed::fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &rhs)
        return *this;
    this->fixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const { return this->fixedPointValue; }

void Fixed::setRawBits(int const raw) { this->fixedPointValue = raw; }

float Fixed::toFloat(void) const {
    return (float)this->fixedPointValue / (1 << Fixed::fractionalBits);
}

int Fixed::toInt(void) const {
    return this->fixedPointValue >> Fixed::fractionalBits;
}

// Overload operator <<
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}
