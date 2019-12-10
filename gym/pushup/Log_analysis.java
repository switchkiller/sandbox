import java.io.*;
import java.util.*;
import java.util.regex.*;


public class Solution {
    private static final Scanner scan = new Scanner(System.in);

    public static void main(String args[]) throws Exception {
        // read the string filename
        String filename;
        filename = scan.nextLine();

        File file = new File(filename);

        BufferedReader bufferedReader = new BufferedReader(new FileReader(filename));

        HashMap<String, Integer> hashMap = new HashMap<>();

        String OUTPUT_FILENAME = "records_" + filename;
        String st;

        while((st = bufferedReader.readLine()) != null){
            String firstWord = st;
            if (firstWord.contains(" ")){
                firstWord = firstWord.substring(0, firstWord.indexOf(" "));
                if (hashMap.containsKey(firstWord)){
                    int value = hashMap.get(firstWord);
                    hashMap.put(firstWord, value+1);
                } else{
                    hashMap.put(firstWord, 1);
                }
            }
        }

        File output = new File(OUTPUT_FILENAME);

        FileWriter writer = new FileWriter(output);
        hashMap.forEach((key,value) -> {
            try{
                writer.write(key + " " + value + "\n");
            } catch (Exception e){
                e.printStackTrace();
            }
            });
        writer.close();

    }
