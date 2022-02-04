package youtube.channel;

public class Follower implements Observer {
    private String name;

    public Follower(String name) {
        this.name = name;
    }

    public void update(String message) {
        System.out.println("Update for " + this.name + ", message: " + message);
    }

    public void play() {
        System.out.println("play...");
    }
}
