package playlist;

import java.util.ArrayList;
import playlist.IComponent;

public class Playlist implements IComponent {

	public String playlistName;
	public ArrayList<IComponent> playlist = new ArrayList<IComponent>();

	public Playlist(String playlistName) {
		this.playlistName = playlistName;
	}

    public String getName() {return this.playlistName;}
    public void play(){}
    public void setPlaybackSpeed(float speed){}


}
