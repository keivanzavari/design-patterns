package composite_playlist.playlist;

import java.util.ArrayList;

public class Playlist implements IComponent {

	public String playlistName;
	public ArrayList<IComponent> playlist = new ArrayList<IComponent>();
	private int currentSong = 0;
	private float speed = 1;

	public Playlist(String playlistName) {
		this.playlistName = playlistName;
	}

	public void add(IComponent playlistOrSong) {
		this.playlist.add(playlistOrSong);
	}

	public String getName() {
		return this.playlistName;
	}

	public void play() {
		this.playlist.get(currentSong).setPlaybackSpeed(this.speed);
		this.playlist.get(currentSong).play();
	}

	public void setPlaybackSpeed(float speed) {
		this.speed = speed;
	}

}
