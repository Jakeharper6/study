package student;

public class Student {
    private String name;

    public Student(String name) {
        this.name = name;
    }

    final String getName() {
        return name;
    }

    final void setName(String name) {
        this.name = name;
    }

    public void study(){
        System.out.println("学习");
    }
}
