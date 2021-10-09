// ConsoleApplication56.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include "AudioProcessor.h"
#include "AudioEditor.h"



int main()
{
	AudioProcessor audioApp;

	std::thread t(&AudioProcessor::invokeProcess, audioApp);
	t.join();
}
