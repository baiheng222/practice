package com.designpatterns.decorator;

public class Mocha extends CondimentDecorator
{
    Beverage mBeverage;
    public Mocha(Beverage beverage)
    {
        mBeverage = beverage;
    }

    public String getDescription()
    {
        return mBeverage.getDescription() + ", Mocha";
    }

    public double cost()
    {
        return .20 + mBeverage.cost();
    }
}