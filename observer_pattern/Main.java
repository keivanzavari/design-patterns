import youtube.channel.Channel;
import youtube.channel.Follower;

public class Main {

    public static void main(String args[]) {
        Channel channel = new Channel("Fun");
        Follower follower_1 = new Follower("xyz");
        Follower follower_2 = new Follower("abc");
        channel.registerObserver(follower_1);
        channel.registerObserver(follower_2);

        channel.notifyObservers();
        System.out.println("main... ");

    }
}
