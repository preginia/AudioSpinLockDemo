#include "pch.h"
#include "AudioProcessor.h"
#include "AudioEditor.h"
#include <iostream>



AudioProcessor::AudioProcessor()
{
	spin = new audio_spin_mutex;
}


AudioProcessor::~AudioProcessor()
{
}

void AudioProcessor::init()
{
	int N = 100;
	sharedResources.resize(N);
	for (int i = 0; i < N; ++i)
	{
		sharedResources[i] = i;
	}

	audioEditor = new AudioEditor(*this);
	audioEditorThread = new std::thread(&AudioEditor::GUILoop, audioEditor);

}
void AudioProcessor::invokeProcess()
{
	init();

	std::chrono::milliseconds timespan(10);
	for (;;) // faked callbacks from sound card
	{
		process();

		std::this_thread::sleep_for(timespan);
	}
	audioEditorThread->join();
}


void AudioProcessor::process()
{
	std::unique_lock<audio_spin_mutex> lock(*spin, std::try_to_lock);

	if (lock.owns_lock()) 
	{
		for (int i = 0; i < sharedResources.size(); ++i)
		{
			std::cout << "Processing data..." << std::endl;
			int sample = sharedResources[i]; // fake data using
		}
	}
	else
	{
		// use a fallback strategy

	}
}
