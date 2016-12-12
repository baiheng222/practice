package com.designpatterns.decorator;

public class DarkRoast extends Beverage
{
    public DarkRoast()
    {
        description = "DarkRost";
    }

    public double cost()
    {
        return 1.00;
    }
}