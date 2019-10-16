
package test;

import java.util.ArrayList;
import java.util.List;

/*
   AMAZON COMMENT FILTERING MECHANISM
 */

class Filter{
    /*
        Instead of arrayList we can also opt for the HashSet

        Problem arrises when the list becomes huge
        as the processing time will increase
        to make sure it will run fast we can make it concurrent and do the same thing using Multiple threads

        or

        we can create the TRIE data structure for the  words storage and fast lookup.
     */

    private static  List<String> abusiveWords = new ArrayList<String>(){{
        add("shit");
        add("ass hole");
        add("asshole");
    }};

    static void  addWords(String word){
        abusiveWords.add(word);
    }

    static boolean filter(String desc){
        desc = desc.toLowerCase();
        String[] words = desc.split(" ");
        boolean passed = true;
        for(String word : words){
            if(abusiveWords.contains(word)){
                passed = false;
                break;
            }
        }
        return passed;
    }
}

class Comment{
    private String comment;
    Comment(String desc){
        comment = desc;
    }

    boolean isValidComment(){
        /*
            Check for the abusive words
         */
        return Filter.filter(comment);
    }
}

public class CommentFiltering {
    public static void main(String[] args) {
        Comment comment = new Comment("This product is like a shit");
        Comment comment1 = new Comment("This product is like very good");
        boolean flag = comment.isValidComment();
        boolean newFlag = comment1.isValidComment();
        System.out.println("Did my Comment passed "+flag);
        System.out.println("Did my Second Comment passed "+newFlag);
    }
}
