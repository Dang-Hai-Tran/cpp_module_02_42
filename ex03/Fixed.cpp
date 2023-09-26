/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:19:03 by datran            #+#    #+#             */
/*   Updated: 2023/09/26 11:18:15 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) { this->fixedPointValue = 0; };

Fixed::Fixed(const Fixed &src) { *this = src; }

Fixed::Fixed(int const n) {
    this->fixedPointValue = n << Fixed::fractionalBits;
}

Fixed::Fixed(float const f) {
    this->fixedPointValue = roundf(f * (1 << Fixed::fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &rhs) {
    if (this == &rhs)
        return *this;
    this->fixedPointValue = rhs.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &rhs) const {
    return (this->fixedPointValue > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const {
    return (this->fixedPointValue < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return (this->fixedPointValue >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return (this->fixedPointValue <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const {
    return (this->fixedPointValue == rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs) const {
    float ret = this->toFloat() + rhs.toFloat();
    return Fixed(ret);
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    float ret = this->toFloat() - rhs.toFloat();
    return Fixed(ret);
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    float ret = this->toFloat() * rhs.toFloat();
    return Fixed(ret);
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    float ret = this->toFloat() / rhs.toFloat();
    return Fixed(ret);
}

Fixed &Fixed::operator++() {
    this->fixedPointValue += 1;
    return *this;
}

Fixed &Fixed::operator++(int) {
    Fixed &tmp = *this;
    ++(*this);
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a <= b) ? a : b; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a <= b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a >= b) ? a : b; }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a >= b) ? a : b;
}

Fixed::~Fixed(void) {}

int Fixed::getRawBits(void) const { return this->fixedPointValue; }

void Fixed::setRawBits(int const raw) { this->fixedPointValue = raw; }

float Fixed::toFloat(void) const {
    return (float)this->fixedPointValue / (1 << Fixed::fractionalBits);
}

int Fixed::toInt(void) const {
    return this->fixedPointValue >> Fixed::fractionalBits;
}

// Overload operator <<
std::ostream &operator<<(std::ostream &os, Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}
