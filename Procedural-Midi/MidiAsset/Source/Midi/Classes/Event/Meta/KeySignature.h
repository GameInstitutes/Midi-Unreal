// Copyright 2011 Alex Leffelman
// Updated 2016 Scott Bishel

#pragma once

#include "MetaEvent.h"

/**
 * 
 */
class MIDI_API KeySignature : public MetaEvent
{
	int mKey;
	int mScale;

public:
	static const int SCALE_MAJOR = 0;
	static const int SCALE_MINOR = 1;

	KeySignature(long tick, long delta, int key, int scale);

	void setKey(int key);
	int getKey();

	void setScale(int scale);
	int getScale();

protected:
	int getEventSize();

public:
	void writeToFile(FMemoryWriter & output);

	static KeySignature * parseKeySignature(long tick, long delta, FBufferReader & input);
	int CompareTo(MidiEvent *other);
};
