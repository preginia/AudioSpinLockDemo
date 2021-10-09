#include "pch.h"
#include "AudioEditor.h"
#include "AudioProcessor.h"
#include <iostream>

#include <array>
#include <thread>
#include <atomic>
#include <vector>


AudioEditor::AudioEditor(AudioProcessor& processor) : processor(processor)
{
}

void AudioEditor::GUILoop()
{
	std::chrono::milliseconds timespan(10);
	for (;;) // faked GUI loop
	{
		std::this_thread::sleep_for(timespan);

		std::unique_lock<audio_spin_mutex> lock(*processor.spin);
		for (int i = 0; i < processor.sharedResources.size(); ++i)
		{
			std::cout << "Turining knob so updating shared resources" << std::endl;
			processor.sharedResources[i] = processor.sharedResources[i] + 1;
		}
	}
}
