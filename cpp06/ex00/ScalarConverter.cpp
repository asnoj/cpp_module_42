/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:51:22 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/26 22:59:37 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>

ScalarConverter::ScalarConverter(void)
{
	std::cout << "[ScalarConverter] Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
	std::cout << "[ScalarConverter] Copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		std::cout << "[ScalarConverter] Assignement operator called" << std::endl;
	}

	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "[ScalarConverter] Destructor called" << std::endl;
}

static bool isPseudo(const std::string &input)
{
	return (input == "+inff" || input == "+inf" || input == "-inff" || input == "-inf" || input == "nan" || input == "nanf");
}

static bool isChar(const std::string &s)
{
	return (s.length() == 1 && isprint(static_cast<unsigned char>(s[0])) && !isdigit(s[0]));
}

static bool isFloat(const std::string &s)
{
	int i = 0;
	if (s[0] == '-')
		i++;
	while (s[i])
	{
		char c = s[i++];
		if (!isdigit(c) && c != 'f' && c != '.')
			return false;
	}
	return (s.find('.') != std::string::npos && s[s.length() - 1] == 'f');
}

static bool isDouble(const std::string &s)
{
	int i = 0;
	if (s[0] == '-')
		i++;
	while (s[i])
	{
		char c = s[i++];
		if (!isdigit(c) && c != '.')
			return false;
	}
	return (s.find('.') != std::string::npos && s[s.length() - 1] != 'f');
}

static bool isInt(const std::string &s)
{
	int i = 0;
	if (s[0] == '-')
		i++;
	while (s[i])
	{
		char c = s[i++];
		if (!isdigit(c))
			return false;
	}
	return (s.find('.') == std::string::npos && s[s.length() - 1] != 'f');
}

static void printChar(double val)
{
	if (std::isnan(val) || std::isinf(val) || val < 0 || val > 127)
		std::cout << "char: impossible\n";
	else if (!isprint(static_cast<int>(val)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(val) << "'\n";
}

static void printInt(double val)
{
	int f;

	std::cout << "int: ";
	if (val < INT_MIN || val > INT_MAX || std::isnan(val) || std::isinf(val))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	f = static_cast<int>(val);
	std::cout << f << std::endl;
}

static void printFloat(double val)
{
	float f;
	std::ostringstream oss;

	f = static_cast<float>(val);
	oss << f;
	std::string s = oss.str();
	std::cout << "float: ";
	if (std::isinf(f))
		std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
	else if (std::isnan(f))
		std::cout << "nanf\n";
	else if (s.find('e') == std::string::npos)
	{
		if (std::fmod(f, 1.0f) == 0.0f)
			std::cout << f << ".0f\n";
		else
			std::cout << f << "f\n";
	}
	else
		std::cout << f << "f\n";
}

static void printDouble(double val)
{
	double d;
	std::ostringstream oss;

	d = static_cast<double>(val);
	oss << d;
	std::string s = oss.str();
	std::cout << "double: ";
	if (std::isinf(d))
		std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
	else if (std::isnan(d))
		std::cout << "nan\n";
	else
	{
		if (d == static_cast<long>(d) && s.find('e') == std::string::npos)
			std::cout << d << ".0\n";
		else
			std::cout << d << "\n";
	}
}

void ScalarConverter::convert(const std::string &s)
{
	double val;

	if (s.empty())
	{
		std::cout << "the conversion is impossible, please enter a valid value\n";
		return;
	}
	else if (isChar(s))
		val = static_cast<double>(s[0]);
	else if (isPseudo(s))
	{
		if (s == "nan" || s == "nanf")
			val = std::numeric_limits<double>::quiet_NaN();
		else if (s == "+inf" || s == "+inff")
			val = std::numeric_limits<double>::infinity();
		else
			val = -std::numeric_limits<double>::infinity();
	}
	else if (isFloat(s))
	{
		val = static_cast<double>(strtof(s.c_str(), NULL));
	}
	else if (isDouble(s))
	{
		val = strtod(s.c_str(), NULL);
	}
	else if (isInt(s))
		val = static_cast<double>(strtol(s.c_str(), NULL, 10));
	else
	{
		std::cout << "the conversion is impossible, please enter a valid value" << std::endl;
		return;
	}

	printChar(val);
	printInt(val);
	printFloat(val);
	printDouble(val);
}
