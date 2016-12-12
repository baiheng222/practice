package com.designpatterns.decorator;

public class Whip extends CondimentDecorator
{
    Beverage mBeverage;
    public Whip(Beverage beverage)
    {
        mBeverage = beverage;
    }

    public String getDescription()
    {
        return mBeverage.getDescription() + ", Whip";
    }

    public double cost()
    {
        return .59 + mBeverage.cost();
    }
}