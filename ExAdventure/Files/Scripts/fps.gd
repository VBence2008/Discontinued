extends Node
var title = "ExAdventure 1.0.0 by Veress Bence Gyula"
func _process(_delta):
	OS.set_window_title(title + " | FPS: " + str(Engine.get_frames_per_second()))
