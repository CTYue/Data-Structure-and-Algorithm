package com.Leetcode;

import java.lang.reflect.Array;
import java.util.*;


public class Main {
    public static void main(String[] args)
    {
        //Java 9 new features
        //Factory Methods for Collection Framework APIS
        List test = List.of();

        List<String> list = List.of("Zidong", "Yu", "Benjamin","Yu");
//        list.add("CTY");//不能添加/修改/删除元素，因为list被初始化为immutableList
//        list.remove(1);

        System.out.println(list+"\n"+list.getClass().getName());

        List<String> list2 = new ArrayList<>(Arrays.asList("Zidong", "Yu", "Benjamin","Yu"));
        System.out.println(list2+"\n"+list2.getClass().getName());

        Map map = Map.of(1,"One", 2,"Two", 3,"Three");
//        System.out.println(map);
//
        System.out.println("\nDemo immutable map...\n");
        //注意，使用immutableMap时，map element其实是object
//        for(Map.Entry e: map.entrySet()) //Wrong
        for(Object e: map.entrySet())
            System.out.println(e.toString());

        System.out.println("\n");

        Map<Integer, String> regularMap = new HashMap<Integer, String>();
        regularMap.put(1, "One");
        regularMap.put(2, "Two");
        regularMap.put(3, "Three");

        for(Map.Entry e: regularMap.entrySet() )
        {
            System.out.println(e.getKey()+": "+e.getValue());
        }

    }
}
