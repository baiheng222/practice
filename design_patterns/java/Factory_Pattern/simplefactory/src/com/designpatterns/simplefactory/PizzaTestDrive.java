package com.designpatterns.simplefactory;

/**
 * Created by baiheng222 on 16-12-22.
 */
public class PizzaTestDrive
{
    public static void main(String[] args)
    {
        SimplePizzaFactory factory = new SimplePizzaFactory();
        PizzaStore pizzaStore = new PizzaStore(factory);

        Pizza pizza = pizzaStore.orderPizza("cheese");
        System.out.println("We order a " + pizza.getName() + "\n");
        System.out.println(pizza);

        pizza = pizzaStore.orderPizza("veggi");
        System.out.println("We order a " + pizza.getName() + "\n");
        System.out.println(pizza);
    }
}
