package com.company;

import java.util.Arrays;

//最小堆
public class Heap {
    Integer [] data;
    int capacity;
    int length;

    Heap(){
        capacity = 20;
        data = new Integer[capacity];
        length = 0;
    }

    boolean enqueue(Integer elem){
        if (length >= 20){
            System.out.println("Heap's capacity is" + capacity + ", enqueue failed");
            return false;
        }

        data[length] = elem;
        int curr = length;
        int father = (curr - 1)/2;

        while (data[curr] < data[father]){
            Integer t = data[curr];
            data[curr] = data[father];
            data[father] = t;
            curr = father;
            father = (curr - 1) / 2;
        }
        length++;
        return true;
    }

    Integer dequeue(){
        if (length == 0)
            return null;

        Integer min = data[0];
        data[0] = data[length - 1];
        length--;
        int curr = 0;
        int left = curr;
        int right = curr;
        if (2 * curr + 1 < length)
            left = 2* curr + 1;
        int minChild = data[left] < data[right] ? left : right;

        while (data[curr] > data[minChild]){
            Integer t = data[curr];
            data[curr] = data[minChild];
            data[minChild] = t;
            curr = minChild;
        }
        
    }

    @Override
    public String toString() {
        return "Heap{" +
                "data=" + Arrays.toString(data) +
                ", capacity=" + capacity +
                ", length=" + length +
                '}';
    }
}
