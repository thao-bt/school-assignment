public class Book {
    String title;
    String author;
    int year;
    boolean isBorrowed;

    Book (String title,String author,int year,boolean isBorrowed) {
        this.title = title;
    }

    //Create getter if title is private
    public String getAuthor(){
        return author;
    }

    public String getTitle(){
        return title;
    }

    public int getYear(){
        return year;
    }

    public boolean getIsBorrowed(){
        return isBorrowed;
    }

    //Create Setter
    public void setAuthor(String newAuthor) {
        this.author = newAuthor;
    }

    public void setTitle(String newTitle){
        this.title =newTitle;
    }

    public void setYear(int newYear){
        this.year = newYear;
    }

    public void setIsborrowed(boolean newIsborrowed){
        this.isBorrowed = newIsborrowed;
    }
}
