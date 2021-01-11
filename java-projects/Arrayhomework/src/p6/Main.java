package p6;

//编写一个方法，根据传入的字符串将字符串数组的元素进行拼接，返回拼接后的字符串
//将一个字符串数组输出为|分割的形式，比如
//arr2={"梅西","卡卡","c罗","罗纳尔多","贝克汉姆"}; concat(arr2,"|") 的结果为 梅西|卡卡|C罗|罗纳尔多|贝克汉姆

public class Main {
    public static String concat(String[] arr, String symbol) {
        String output = "";
        for (int i = 0; i < arr.length; i++) {
            output += arr[i];
            if (i < arr.length - 1){
                output += symbol;
            }
        }

        return output;
    }

    public static void main(String[] args) {
        String[] arr2 = {"梅西","卡卡","c罗","罗纳尔多","贝克汉姆"};
        System.out.println(concat(arr2,"|"));
    }
}
