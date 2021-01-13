package PizzaPracRedo;

public class SeafoodPizza extends Pizza{
    private String ingredients;

    public String getIngredients() {
        return ingredients;
    }

    public void setIngredients(String ingredients) {
        this.ingredients = ingredients;
    }

    public SeafoodPizza(String name, int price, int size, String ingredients) {
        super(name, price, size);
        this.ingredients = ingredients;
    }

    @Override
    public String show() {
        return "名称：" + getName() + "\n价格：" + getPrice() + "元" + "\n大小：" + getSize() + "寸" + "\n配料：" + ingredients;
    }
}
