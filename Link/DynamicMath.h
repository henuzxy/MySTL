/*************************************************************************
	> File Name: DynamicMath.h
	> Author: 
	> Mail: 
	> Created Time: 四  4/ 2 14:09:48 2020
 ************************************************************************/

#ifndef _DYNAMICMATH_H
#define _DYNAMICMATH_H
class DynamicMath{
public:
    DynamicMath() = default;
    ~DynamicMath() = default;

    static double add(double a,double b);
    static double sub(double a,double b);
    static double mul(double a,double b);
    static double div(double a,double b);
    void print();
};
#endif
