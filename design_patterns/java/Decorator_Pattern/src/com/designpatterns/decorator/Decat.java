package com.designpatterns.decorator;

public class Decat extends Beverage
{
    public Decat()
    {
        description = "DarkRost";
    }

    public double cost()
    {
        return 0.97;
    }
}