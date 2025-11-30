import java.util.ArrayList;

// Trong java dung arraylist vi dung array bi gioi han dung luong
public class Main {
    public static void main(String[] args) {
        //Book[] list = new Book[30];
        ArrayList<Book> list = new ArrayList<Book>();

        list.add(new Book("a","b",5,true));
        list.get(0).author =  "Adam";

        //Dung vong lap de xin cap phat bo nho
        /*
        for (int i =0;i<30;i++){
            list[i] = new Book();
        }

        /*
        list[0] = new Book();
        list[0].author = "Peter"; //phai xin cap phat bo nho rieng cho tung phan tu cua mang

        list[1] = new Book();
        list[1].author = "David";
         */

        System.out.println(list.get(0).author);
    }
}