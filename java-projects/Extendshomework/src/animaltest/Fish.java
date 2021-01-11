package animaltest;

public class Fish extends Animal{
    public Fish(int age, double weight) {
        super(age, weight);
    }

    public void swim(){
        System.out.println("I can swim.");
    }
}
