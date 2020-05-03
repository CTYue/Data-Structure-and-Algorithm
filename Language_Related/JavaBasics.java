import java.io.BufferedReader;
import java.io.FileReader;
import java.util.*;

public class JavaBasics
{
    public static <T> T mostCommon(List<T> list) {
        Map<T, Integer> map = new HashMap<>();

        for (T t : list) {
            Integer val = map.get(t);
            map.put(t, val == null ? 1 : val + 1);
        }

        Map.Entry<T, Integer> max = null;

        for (Map.Entry<T, Integer> it : map.entrySet())
        {
            if (max == null || it.getValue() > max.getValue())
                max = it;
        }

        return max.getKey();//
    }


    //Task 4
    public static boolean checkPalindrome(String input)
    {
        if(input.isEmpty()) return true;

        int left=0, right=input.length()-1;
        char leftChar, rightChar;

        while(left <= right)
        {
            leftChar=input.charAt(left);
            rightChar=input.charAt(right);
            //Consider only letters and digits
            if(!Character.isLetterOrDigit(leftChar))
                left++;
            else if(!Character.isLetterOrDigit(rightChar))
                right--;
            //Ignore casing issue
            else
            {
                if(Character.toLowerCase(leftChar)!=Character.toLowerCase(rightChar))
                    return false;

                left++;
                right--;
            }
        }

        return true;
    }

    //Task 9
    public static ArrayList<Integer> findMissingNumbers(int[] given)
    {
        ArrayList<Integer> res = new ArrayList<Integer>();
        int[] temp=new int[given.length];

        for(int num: given)
        {
           temp[num-1]=1;
        }

        for(int i=0;i<temp.length;++i)
        {
            if(temp[i]==0)  res.add(i+1);
        }

        return res;
    }

    //Task 10
    public static String findMostFrequency(String path) throws Exception
    {
        String res;

        String line, word;
        ArrayList<String> words=new ArrayList<String>();

        FileReader file=new FileReader(path);
        BufferedReader buffer = new BufferedReader(file);

        //Read lines and split words
        while((line = buffer.readLine()) != null)
        {
            //"(?:(?<![a-zA-Z])'|'(?![a-zA-Z])|[^a-zA-Z'])+"
            String str[]=line.toLowerCase().split("(?:(?<![a-zA-Z])'|'(?![a-zA-Z])|[^a-zA-Z'])+");//Split by Punctuations
            for(String s: str)  words.add(s);
        }

        res=mostCommon(words);

        return res;
    }

    public static void main(String[] args) throws Exception {
        //Task 1
        String test = "Hello world from Marlabs";
        StringBuilder sb = new StringBuilder();

        System.out.println("===================");
        System.out.println("Task 1");
        System.out.println("Original string: "+test);
        for (int i=0;i<test.length();++i)
        {
            sb.insert(0, test.charAt(i));
        }
        System.out.println("Reversed string: "+sb.toString());


        //Task 2
        System.out.println("===================");
        System.out.println("Task 2");
        HashMap<String, Integer> count = new HashMap<String, Integer>();
        String sentence="Hello Hello World World from Marlabs";
        String[] words=sentence.split(" ");
        System.out.println("Sentence: "+sentence);
        //
        for(int i=0;i<words.length;++i)
        {
            if(count.containsKey(words[i]))
            {
                count.put(words[i], count.get(words[i])+1);
            }
            else
                count.put(words[i], 1);
        }

        //Print occurrence
        for(Map.Entry<String, Integer> entry: count.entrySet())
        {
            System.out.println("Word: "+entry.getKey()+" || Occurrence: "+entry.getValue());
        }


        //Task 3
        System.out.println("===================");
        System.out.println("Task 3");
        HashMap<Integer, String> hashMap=new HashMap<>();
        hashMap.put(0, "Hello");
        hashMap.put(1, "World");
        hashMap.put(2, "from ");
        hashMap.put(3, "Marlabs");

        //Iterate using while
        Iterator<Map.Entry<Integer, String>> it = hashMap.entrySet().iterator();

        System.out.println("Iterate HashMap using while: ");
        while(it.hasNext())
        {
            Map.Entry<Integer, String> pair = (Map.Entry<Integer, String>)it.next();
            System.out.println(pair.getKey() +": "+pair.getValue());
        }

        //Iterate using for-each loop
        System.out.println("Iterate HashMap using foreach loop: ");
        for(Map.Entry<Integer, String> entry: hashMap.entrySet())
        {
            System.out.println(entry.getKey()+": "+entry.getValue());
        }

        //Task 4
        System.out.println("===================");
        System.out.println("Task 4");

        String palindrome_str="A man, a plan, a canal: Panama";
        System.out.println("Input string: "+palindrome_str);
        //Check palindrome
        if(checkPalindrome(palindrome_str)==true)
            System.out.println("Yes, it's palindrome!");
        else
        {
            System.out.println("No, it's NOT palindrome!");
        }


            //Task 5
        System.out.println("===================");
        System.out.println("Task 5");

        ArrayList<Integer> arr=new ArrayList<Integer>();
        arr.add(1);
        arr.add(2);
        arr.add(3);
        arr.add(4);
        arr.add(5);
        arr.add(6);
        arr.add(7);

        //Iterate using for-loop
        for(int i=0;i<arr.size();++i)
        {
            System.out.println("Index: "+i+", Value: "+arr.get(i));
        }

        //Iterate using while loop
        Iterator<Integer> it_arr = arr.iterator();

        while(it_arr.hasNext())
        {
            System.out.println("Value:  "+it_arr.next());
        }
        System.out.println();

        //Iterate using advance for loop
        for(Integer item: arr)
        {
            System.out.println("Value:  "+item);
        }

        //Task 6
        System.out.println("===================");
        System.out.println("Task 6");

        String dup="aabbbcdeffg";
        System.out.println("Input: "+dup);
        int[] dup_count=new int[26];
        Arrays.fill(dup_count, 0);

        for(char ch: dup.toCharArray())
        {
            dup_count[ch-'a']++;
        }

        //Print all duplicates
        System.out.println("Duplicate characters are as below: ");
        for(int i=0;i<dup_count.length;++i)
        {
            if(dup_count[i]>1)
            {
                char temp = (char)('a'+i);
                System.out.println("Character: "+temp);
            }
        }

        //Task 7
        System.out.println("===================");
        System.out.println("Task 7");
        int[] int_arr={9,5,8,7,4,6,3,1,2};

        //Find the second highest number in the given array
        Arrays.sort(int_arr);
        System.out.print("Sorted array: \n");
        for(int item: int_arr)
        {
            System.out.print(item+" ");
        }
        System.out.println("\nThe second highest number is: "+int_arr[1]);

        //Task 8
        System.out.println("===================");
        System.out.println("Task 8");
        String input_spaces="M ar l ab s";
        System.out.println("Original input with spaces: "+input_spaces);
        StringBuilder nospaceSB=new StringBuilder();

        //Remove all spaces
        for(Character ch: input_spaces.toCharArray())
        {
            if(ch!=' ')
            {
                nospaceSB.append(ch);
            }
        }

        System.out.println("Output without spaces: "+nospaceSB.toString());

        //Task 9
        System.out.println("===================");
        System.out.println("Task 9");
        //e.g. Given {1,1,2,2,4}, the length of the array is 5
        //missing numbers are 3 and 5
        int[] given={1,1,2,2,4};
        ArrayList<Integer> res=findMissingNumbers(given);

        System.out.println("Missing numbers are: ");
        for(Integer num: res)
        {
            System.out.println(num);
        }


        //Task 10
        System.out.println("===================");
        System.out.println("Task 10");
        //Sample text file name: text.txt
        String path="text.txt";
        System.out.println("Current dir:" + System.getProperty("user.dir"));

        String mostCommon=findMostFrequency(path);
        System.out.println("The most common word is: "+ mostCommon);
    }
}
