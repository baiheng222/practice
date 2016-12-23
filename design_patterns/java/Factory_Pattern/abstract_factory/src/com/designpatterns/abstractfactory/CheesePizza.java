package com.designpatterns.abstractfactory;

/**
 * Created by baiheng222 on 16-12-23.
 */
public class CheesePizza extends Pizza
{
    PizzaIngredientFactory ingredientFactory;
    public CheesePizza(PizzaIngredientFactory fc)
    {
        ingredientFactory = fc;
    }

    void prepare()
    {
        System.out.println("Preparing " + name);
        dough = ingredientFactory.createDough();
        sauce = ingredientFactory.createSauce();
        cheese = ingredientFactory.createCheese();
    }
}
