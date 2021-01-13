package PizzaPracRedo;

public class BaconPizza extends Pizza{
    private int grams;

    public int getGrams() {
        return grams;
    }

    public void setGrams(int grams) {
        this.grams = grams;
    }

    public BaconPizza(String name, int price, int size, int grams) {
        super(name, price, size);
        this.grams = grams;
    }

    @Override
    public String show() {
        return "名称：" + getName() + "\n价格：" + getPrice() + "元" + "\n大小：" + getSize() + "寸" + "\n培根克数：" + grams + "克";
    }
}
