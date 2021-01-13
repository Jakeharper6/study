package AnimalPrac;

public class Main {
    public static void main(String[] args) {
        Girl girl = new Girl();

//        父类引用指向子类对象
//        Cat cat = new Cat();
//        Animal animal = cat;
//        Animal animal = new Cat();
        Animal animal = new Pig();//向上转型

//        Animal animal = new Animal();

        Pig pig2 = (Pig)animal;//向下转型

        pig2.shout();
        pig2.sleep();
    }
}
