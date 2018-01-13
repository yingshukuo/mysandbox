# portsf.md

## Quick Use Case?

## What is portsf?
As far as I understand, portsf is a library that supports format conversion
between audio format (wav) and a stream of values.

## What do we have?
NOTE: The list is not exhausted! It's only for learning purpose.
For complete list, please check out ```portsf.h``` directly

### Data Type
* psf_stype = Sample type (float? or how many bytes?)
* psf_format = Audio file format (unk, stdwave, wave_ex, aiff, aifc)
* psf_channelformat = Audio channel format
* psf_props = srate + nchan + psf_stype + psf_format + psf_channelformat

### Functions
* int psf_init();
    - initialize system
* int psf_finish();
    - close system

* int psf_sndCreate(const char \*path, const PSF_PROPS \*props, ...);
    - create sound file with props and spawn the file in path
* int psf_sndOpen(const char \*path, PSF_PROPS \*props, ...);
    - open existed sound file with given path and props
* int psf_sndClose(int sfd);
    - close the sound file with given fd

* int psf_sndSize(int sfd);
    - get size of file

* int psf_sndWriteFloatFrames(int sfd, const float \*buf, DWORD nFrames);
* int psf_sndWriteDoubleFrames(int sfd, const double \*buf, DWORD nFrames);
    - write multi-channel frames of floats
* int psf_sndReadFloatFrames(int sfd, float \*buf, DWORD nFrames);
* int psf_sndReadDoubleFrames(int sfd, double \*buf, DWORD nFrames);
    - read multi-channel sample frames into floats buffer

* int psf_sndTell(int sfd);
    - get current multi-channel frame position in file
* int psf_sndSeek(int sfd,int offset,int seekmode);
    - multi-channel frame wrapper for stdio fseek

* psf_format psf_getFormatExt(const char *path);
    - find the soundfile format from the filename extension


