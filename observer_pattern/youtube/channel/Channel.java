package youtube.channel;

public class Channel extends Subject {
    private String name;
    private String status;

    public Channel(String name) {
        this.name = name;
        this.status = "NOT VIEWED";
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public String getStatus() {
        return this.status;
    }
}
