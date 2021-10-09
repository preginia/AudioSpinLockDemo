#pragma once

class AudioProcessor;

class AudioEditor
{
public:
	AudioProcessor& processor;

	AudioEditor(AudioProcessor& processor) ;
	void GUILoop();
};
