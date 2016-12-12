package com.designpatterns.decorator;

public class Soy extends CondimentDecorator
{
    Beverage mBeverage;
    public Soy(Beverage beverage)
    {
        mBeverage = beverage;
    }

    public String getDescription()
    {
        return mBeverage.getDescription() + ", Soy";
    }

    public double cost()
    {
        return .13 + mBeverage.cost();
    }
}