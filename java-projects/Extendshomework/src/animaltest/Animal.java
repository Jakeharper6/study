package animaltest;

public class Animal {
    private int age;
    private double weight;

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public Animal() {
    }

    public Animal(int age,double weight) {
        this.age = age;
        this.weight = weight;
    }

    protected String output(){
        return "age:" + age + ",weight" + weight;
    }
}
