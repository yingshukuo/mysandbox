# portsf.md

## Quick Use Case?

## What is portsf?
As far as I understand, portsf is a library that supports format conversion
between audio format (wav) and a stream of values.

## What do we have?

### Data Type
* psf_stype = Sample type (float? or how many bytes?)
* psf_format = Audio file format (unk, stdwave, wave_ex, aiff, aifc)
* psf_channelformat = Audio channel format
* psf_chpeak = PEAK chunk (not sure if it's still compatible, for broadcasting?)
* psf_props = srate + nchan + psf_stype + psf_format + psf_channelformat

### Functions
* int psf_init();
    - initialize system
* int psf_finish();
    - close system

* int psf_sndCreate(const char *path,
                    const PSF_PROPS *props,
                    int clip_floats,
                    int minheader,
                    int mode);
    - create sound file with props and spawn the file in path
* int psf_sndOpen(const char *path,
                  PSF_PROPS *props,
                  int rescale);
    - open existed sound file with given path and props
* int psf_sndClose(int sfd);
    - close the sound file with given fd


