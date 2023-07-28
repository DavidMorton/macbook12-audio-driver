# Basic info on the device

The device is a Cirrus 4208 and the subsystem id is 106B6400

The inf file has this reference to it...

    %HdAudioFunctionDriver.CS4208_106B6400.DeviceDesc% =HDAudio.Cirrus_CONF_0807, HDAUDIO\FUNC_01&VEN_1013&DEV_4208&SUBSYS_106B6400

Searching the file for HDAudio.Cirrus_CONF_0807 results in several configs

This is probably the main inf config we need to implement:

    [HDAudio.Cirrus_CONF_0807]
    Include=hdaudio.inf
    Needs=HdAudOEM.CopyFiles, HdAudOEM.AddReg, CSHDA.Conf
    DelReg=HDAudio.Cirrus.LFDParams.DelReg
    AddReg=CDB4208AmpCapsOverride, Settings4208CommonFixes, SettingsAllIdlePowerdown, Settings4208HSTypeDetect
    AddReg=CONF_08xx.PinConfigOverride, CONF_0807.PinConfigOverride, CONF_0807.InitVerbs, CONF_0807.Gpio, CONF_0807.APOParams

So the following registries are added:

* CONF_08xx.PinConfigOverride
* CONF_0807.PinConfigOverride
* CONF_0807.InitVerbs
* CONF_0807.Gpio
* CONF_0807.APOParams

## CONF_08xx.PinConfigOverride

    [CONF_08xx.PinConfigOverride]
    ;; baseline pin config overrides for CONF_08xx (HP only)

    HKR,PinConfigOverrideVerbs,FriendlyName,,CS4208 (CONF_08xx)

    HKR,PinConfigOverrideVerbs,0000, 0x1,f0,1c,07,01	; HP: ASSN=Fh, SEQ=0h			*
    HKR,PinConfigOverrideVerbs,0001, 0x1,20,1d,07,01	; HP: COL=gray				*
    HKR,PinConfigOverrideVerbs,0002, 0x1,21,1e,07,01	; HP: DD=HP, CTYP=1/8"			*
    HKR,PinConfigOverrideVerbs,0003, 0x1,03,1f,07,01	; HP: PCON=jack, LOC=prim/left

    HKR,PinConfigOverrideVerbs,0007, 0x1,50,1f,17,01	; LO1: PCON=n/c, LOC=int		*
    HKR,PinConfigOverrideVerbs,0011, 0x1,50,1f,27,01	; LO2: PCON=n/c, LOC=int		*
    HKR,PinConfigOverrideVerbs,0015, 0x1,50,1f,37,01	; LO3: PCON=n/c, LOC=int		*
    HKR,PinConfigOverrideVerbs,0019, 0x1,50,1f,47,01	; LO4: PCON=n/c, LOC=int		*
    HKR,PinConfigOverrideVerbs,0023, 0x1,77,1f,57,01	; MI1: PCON=n/c, LOC=mob lid/ins	*
    HKR,PinConfigOverrideVerbs,0027, 0x1,77,1f,67,01	; MI2: PCON=n/c, LOC=mob lid/ins	*
    HKR,PinConfigOverrideVerbs,0031, 0x1,43,1f,77,01	; LI: PCON=n/c, LOC=prim/left		*
    HKR,PinConfigOverrideVerbs,0035, 0x1,43,1f,87,01	; HS: PCON=n/c, LOC=prim/left		*
    HKR,PinConfigOverrideVerbs,0039, 0x1,77,1f,97,01	; DM1: PCON=n/c, LOC=mob lid/ins	*
    HKR,PinConfigOverrideVerbs,0043, 0x1,77,1f,a7,01	; DM2: PCON=n/c, LOC=mob lid/ins	*
    HKR,PinConfigOverrideVerbs,0047, 0x1,77,1f,b7,01	; DM3: PCON=n/c, LOC=mob lid/ins	*
    HKR,PinConfigOverrideVerbs,0051, 0x1,77,1f,c7,01	; DM4: PCON=n/c, LOC=mob lid/ins	*
    HKR,PinConfigOverrideVerbs,0055, 0x1,50,1f,d7,01	; TX1: PCON=n/c, LOC=int		*
    HKR,PinConfigOverrideVerbs,0059, 0x1,50,1f,e7,01	; TX2: PCON=n/c, LOC=int		*
    HKR,PinConfigOverrideVerbs,0063, 0x1,50,1f,f7,01	; RX1: PCON=n/c, LOC=int		*
    HKR,PinConfigOverrideVerbs,0067, 0x1,50,1f,07,02	; RX2: PCON=n/c, LOC=int		*
    HKR,PinConfigOverrideVerbs,0071, 0x1,43,1f,17,02	; SPDO: PCON=n/c, LOC=prim/left		*
    HKR,PinConfigOverrideVerbs,0075, 0x1,43,1f,27,02	; SPDI: PCON=n/c, LOC=prim/left		*

    HKR,PinConfigOverrideVerbs,NumVerbs, 0x1,4C,00,00,00

## CONF_0807.PinConfigOverride

    [CONF_0807.PinConfigOverride]
    ;; pin config overrides for CONF_0807 (~HP, +HS, +DM1, +TX1)

    HKR,PinConfigOverrideVerbs,FriendlyName,,CS4208 (CONF_0807)

    HKR,PinConfigOverrideVerbs,0002, 0x1,2b,1e,07,01	; HP: DD=HP, CTYP=combo

    HKR,PinConfigOverrideVerbs,0032, 0x1,50,1c,87,01	; HS: ASSN=5h, SEQ=0h			*
    HKR,PinConfigOverrideVerbs,0033, 0x1,20,1d,87,01	; HS: COL=gray				*
    HKR,PinConfigOverrideVerbs,0034, 0x1,ab,1e,87,01	; HS: DD=MI, CTYP=combo
    HKR,PinConfigOverrideVerbs,0035, 0x1,03,1f,87,01	; HS: PCON=jack, LOC=prim/left

    HKR,PinConfigOverrideVerbs,0036, 0x1,70,1c,97,01	; DM1: ASSN=7h, SEQ=0h			*
    HKR,PinConfigOverrideVerbs,0037, 0x1,00,1d,97,01	; DM1: COL=unkn
    HKR,PinConfigOverrideVerbs,0038, 0x1,a0,1e,97,01	; DM1: DD=MI, CTYP=unkn			*
    HKR,PinConfigOverrideVerbs,0039, 0x1,90,1f,97,01	; DM1: PCON=fixed, LOC=int		*

    HKR,PinConfigOverrideVerbs,0052, 0x1,10,1c,d7,01	; TX1: ASSN=1h, SEQ=0h			*
    HKR,PinConfigOverrideVerbs,0053, 0x1,00,1d,d7,01	; TX1: COL=unkn
    HKR,PinConfigOverrideVerbs,0054, 0x1,40,1e,d7,01	; TX1: DD=SPDO, CTYP=unkn		*
    HKR,PinConfigOverrideVerbs,0055, 0x1,90,1f,d7,01	; TX1: PCON=fixed, LOC=int

# CONF_0807.InitVerbs

    [CONF_0807.InitVerbs]
    HKR,cs420x,InitVerbs,1,\					;
    00,05,17,00,\							; AFG: PS-Set = D0
    01,03,47,02,\							; VPW: proc on
    00,00,45,02,  80,00,44,02,\					; CIR=00h, coeff=0080h (SPCC = 10b, SP1M = 0b)
    04,00,45,02,  04,0C,44,02,\					; CIR=04h, coeff=0C04h (TX1 ch 0: slot  4, ch 1: slot 12)
    05,00,45,02,  00,10,44,02,\					; CIR=05h, coeff=1000h (TX1 ch 2: slot  0, ch 3: slot 16)
    1D,00,45,02,  F6,0B,44,02,\					; CIR=1Dh, coeff=0BF6h (DC detect level = 36h)
    33,00,45,02,  93,44,44,02,\					; CIR=33h, coeff=4493h (A/C Gat, A2/C Inv, A1/A2/C ICS)
    34,00,45,02,  13,1B,44,02,\					; CIR=34h, coeff=1B13h (A1/A2/C Enable, A threshold = 250 mV)
    36,00,45,02,	34,00,44,02,\					; CIR=36h, coeff=0034h (SP1 slew rate = slow)
    40,00,45,02,  99,99,44,02,\					; VPW: test mode on
    50,00,45,02,  8B,00,44,02,\					; CIR=50h, coeff=008Bh [00CBh] (jack sense hysteresis = 100 us)
    40,00,45,02,  00,00,44,02					; VPW: test mode off

    ;;  33,00,45,02,  53,44,44,02,\					; CIR=33h, coeff=4453h (A/C Gat, A1/C Inv, A1/A2/C ICS)		[CDB test only - invert A1, don't invert A2]

    HKR,cs420x,n06AllowedInAmpIndex,%REG_BINARY%,	02		; ADC1: only allow SetAmpGain verbs with index=2

    HKR,cs420x,n0AWidgetCaps,	%REG_DWORD%,	0x00042631	; TX1: override widget caps: CCE=1
    HKR,cs420x,n0ASuppBitsRates,	%REG_DWORD%,	0x000E0040	; TX1: override rate caps: -R6

## CONF_0807.Gpio

    [CONF_0807.Gpio]
    HKR,cs420x,Gpio0ExtAmpCfg,	%REG_BINARY%,	0A,00,00,01	; GPIO0 is an output controlled by TX1 PS-Set
    HKR,cs420x,Gpio4ExtAmpCfg,	%REG_BINARY%,	01,00,00,01	; GPIO4 is an output controlled by AFG PS-Set (to HS3 DFET)
    HKR,cs420x,Gpio5ExtAmpCfg,	%REG_BINARY%,	01,00,00,01	; GPIO5 is an output controlled by AFG PS-Set (to HS4 DFET)

## CONF_0807.APOParams

    [CONF_0807.APOParams]
    ;; AB 100
    ;; woofer/tweeter: HPF + HPF + 9-ch PEQ + HSF
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\0", "Type", %REG_DWORD%, 2
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\0", "f0", %REG_DWORD%, 134
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\0", "Q", %REG_DWORD%, 66
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\1", "Type", %REG_DWORD%, 2
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\1", "f0", %REG_DWORD%, 137
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\1", "Q", %REG_DWORD%, 66
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\2", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\2", "f0", %REG_DWORD%, 354
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\2", "GaindB", %REG_DWORD%, -264
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\2", "Q", %REG_DWORD%, 19
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\3", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\3", "f0", %REG_DWORD%, 103
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\3", "GaindB", %REG_DWORD%, 240
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\3", "Q", %REG_DWORD%, 29
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\4", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\4", "f0", %REG_DWORD%, 6757
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\4", "GaindB", %REG_DWORD%, 144
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\4", "Q", %REG_DWORD%, 50
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\5", "Type", %REG_DWORD%, 8
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\5", "f0", %REG_DWORD%, 6158
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\5", "GaindB", %REG_DWORD%, -440
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\5", "Q", %REG_DWORD%, 61
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\6", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\6", "f0", %REG_DWORD%, 60
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\6", "GaindB", %REG_DWORD%, 1800
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\6", "Q", %REG_DWORD%, 139
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\7", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\7", "f0", %REG_DWORD%, 892
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\7", "GaindB", %REG_DWORD%, -1000
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\7", "Q", %REG_DWORD%, 159
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\8", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\8", "f0", %REG_DWORD%, 4907
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\8", "GaindB", %REG_DWORD%, 414
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\8", "Q", %REG_DWORD%, 62
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\9", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\9", "f0", %REG_DWORD%, 60
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\9", "GaindB", %REG_DWORD%, -500
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\9", "Q", %REG_DWORD%, 48
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\10", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\10", "f0", %REG_DWORD%, 1226
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\10", "GaindB", %REG_DWORD%, -567
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\10", "Q", %REG_DWORD%, 97
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\11", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\11", "f0", %REG_DWORD%, 274
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\11", "GaindB", %REG_DWORD%, 212
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\0\\11", "Q", %REG_DWORD%, 29
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\0", "Type", %REG_DWORD%, 2
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\0", "f0", %REG_DWORD%, 134
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\0", "Q", %REG_DWORD%, 66
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\1", "Type", %REG_DWORD%, 2
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\1", "f0", %REG_DWORD%, 137
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\1", "Q", %REG_DWORD%, 66
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\2", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\2", "f0", %REG_DWORD%, 354
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\2", "GaindB", %REG_DWORD%, -264
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\2", "Q", %REG_DWORD%, 19
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\3", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\3", "f0", %REG_DWORD%, 103
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\3", "GaindB", %REG_DWORD%, 240
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\3", "Q", %REG_DWORD%, 29
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\4", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\4", "f0", %REG_DWORD%, 6757
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\4", "GaindB", %REG_DWORD%, 144
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\4", "Q", %REG_DWORD%, 50
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\5", "Type", %REG_DWORD%, 8
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\5", "f0", %REG_DWORD%, 6158
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\5", "GaindB", %REG_DWORD%, -440
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\5", "Q", %REG_DWORD%, 61
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\6", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\6", "f0", %REG_DWORD%, 60
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\6", "GaindB", %REG_DWORD%, 1800
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\6", "Q", %REG_DWORD%, 139
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\7", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\7", "f0", %REG_DWORD%, 892
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\7", "GaindB", %REG_DWORD%, -1000
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\7", "Q", %REG_DWORD%, 159
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\8", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\8", "f0", %REG_DWORD%, 4907
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\8", "GaindB", %REG_DWORD%, 414
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\8", "Q", %REG_DWORD%, 62
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\9", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\9", "f0", %REG_DWORD%, 60
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\9", "GaindB", %REG_DWORD%, -500
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\9", "Q", %REG_DWORD%, 48
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\10", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\10", "f0", %REG_DWORD%, 1226
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\10", "GaindB", %REG_DWORD%, -567
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\10", "Q", %REG_DWORD%, 97
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\11", "Type", %REG_DWORD%, 6
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\11", "f0", %REG_DWORD%, 274
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\11", "GaindB", %REG_DWORD%, 212
    HKLM,"Software\\Cirrus\\APO\\FilterAPO\\1\\11", "Q", %REG_DWORD%, 29

    ;; ======================================================================================

## By example: MBP11

106b5e00

Uses HDAudio.Cirrus_CONF_0803

CONF_08xx.PinConfigOverride, CONF_0802.PinConfigOverride, CONF_0802.InitVerbs, CONF_0802.Gpio, CONF_0803.APOParams

## By example MBA6

106b7200 -> HDAudio.Cirrus_CONF_0800 -> CONF_08xx.PinConfigOverride, CONF_0800.PinConfigOverride
106b7100 -> HDAudio.Cirrus_CONF_0801 -> CONF_08xx.PinConfigOverride, CONF_0800.PinConfigOverride

## There are no speaker outs coming from alsa...

I think this may be at the root of the issue...

Evidence:

    [    5.995611] snd_hda_codec_cirrus hdaudioC0D0: autoconfig for CS4208: line_outs=1 (0x1d/0x0/0x0/0x0/0x0) type:speaker
    [    5.995620] snd_hda_codec_cirrus hdaudioC0D0:    speaker_outs=0 (0x0/0x0/0x0/0x0/0x0)
    [    5.995625] snd_hda_codec_cirrus hdaudioC0D0:    hp_outs=1 (0x10/0x0/0x0/0x0/0x0)
    [    5.995628] snd_hda_codec_cirrus hdaudioC0D0:    mono: mono_out=0x0
    [    5.995631] snd_hda_codec_cirrus hdaudioC0D0:    inputs:
    [    5.995633] snd_hda_codec_cirrus hdaudioC0D0:      Internal Mic=0x19
    [    5.995636] snd_hda_codec_cirrus hdaudioC0D0:      Mic=0x18

There's a dev switch in hda_parser_auto.c at line 220

This comes from get_defcfg_device which accepts def_conf.

def_conf comes from snd_hda_codec_get_pincfg(codec, nid)
* codec is the same object
* nid is passed in
* line 203 in hda_auto_parser

### snd_hda_codec_get_pincfg

This comes from hda_codec.c around line 528 or so.

It first checks for whether the pin exists in the user_pins collection, then the driver_pins collection, then the init_pins collection. 

nid is an hda_nid_t

hid_nid_t is a u16, which is an unsigned short

Managed to get several of the packages built by modifying the makefile and copying over more files.

Now, the 0x1d is being discovered as an AC JACK SPEAKER, but is being ignored by wcaps. The get_wcaps method is what returns this value to the caller.

get_wcaps seems to depend on codec->core.start_nid and nid number, getting the codec->wcaps value at the index of nid-start_nid or returning 0 if it's out of that bounds. (The 4208 patch has an override on this). 

So what is wcaps?

number of nodes is 35, and the start node is 2. 2+35 = 37.

# Alsa files
### Starting

http://alsa-project.org/db/?f=ce64ed0d4758ad8c82729f65196d03f096854d22

### Attempt 1
Attempted to change the pin configs, but they never changed

http://alsa-project.org/db/?f=5130d3b650be85666ca7f635d9aa0abaf9938325

### Attempt 2
Removed the filter around setting the pins... previously this was checking to see if the HDA_FIXUP_ACT_PROBE was set for the action. Loads of weird driver pin configs are now appearing... I need to check that and figure out what's going on.

http://alsa-project.org/db/?f=a54c8639f40c063b95fecaa6d8f8ae4a94978710

### Attempt 3
After fixing some pin locations, the output is now saying it's "Digital Output (S/PDIF) - Built-in Audio" in the mixer in settings. This is a change. S/PDIF and S/PDIF Default PCM both lack volume controls in alsa-mixer. 

http://alsa-project.org/db/?f=e8c37be357e9991b2be1ee719bfdf97a8207ceea

### Attempt 4
Replaced the pin configuration with the one that came straight from Windows according to Leif Liddy's post. Internal mic still works, not much has changed otherwise. It seems that the label from 0x01 in the previous setup is now gone, and there's less detail in alsa-info than there was before about that node.  Headphones are no longer working, though...

http://alsa-project.org/db/?f=d611b443886d1122285a73bbc819791aacb03f00

### 2023-07-26-16-04
Replaced the pin config the way it was before, but headphone sound still isn't coming through...

http://alsa-project.org/db/?f=4cc7e14917ca7a2afaddc90add004fa951a9bce6

### 2023-07-26-16-15
Putting verbs back the way they were before. Headphone sound is back! 
The IRQ shifted from 51 to 52, but I'm not sure if that has anything to do with it.
Node 0x06 Capture volume was changed from D0 to D3, and the Converter stream went from 0 to 1

**Something is wrong with the verbs**

http://alsa-project.org/db/?f=c6c8a3157e13c2c47c1a39a939ed3ffec6f2f6fb

### 2023-07-27-06-44

A note: The structure accepted by the set_pincfg consists of NIDs and a cfg value. 

If a pin matches 0x40000000 then it's apparently an ignored pin.

The enums at the top of hda_auto_parser.h seem to have something to do with what the pin configurations are. 

Following the thread to AC_PAR_PIN_CAP (0x0c), it seems that maybe these (at the top if hda_verbs.h) are the definitions of what each bit does in the pincfg?

hda_proc.c has a print_pin_caps method that seems to detail this somehow? It calls param_read... This param_read maps to snd_hdac_read_parm_uncached (hdac_device.c). This, in turn, uses snd_hdac_regmap_encode_verb (hda_regmap.h)...

    #define snd_hdac_regmap_encode_verb(nid, verb)		\
	(((verb) << 8) | 0x80000 | ((unsigned int)(nid) << 20))

In this situation, verb is AC_PAR_PIN_CAP (0x0c), which would mean it's     

    (0x0c << 8) | 0x80000 | ((unsigned int)(nid) << 20)

This would return back something like 0x1d80c00 for 0x1d

This value is then sent (as cmd) into snd_hdac_regmap_read_raw_uncached (as "reg" in hdac_regmap.c) which points to __snd_hdac_regmap_read_raw.

This calls hda_reg_read (hdac_regmap.c), which calls get_verb...

get_verb is defined as

    (((reg) >> 8) & 0xfff)

Which would, in this case, return back (as "verb") 80c for our earlier 0x1d80c00 thing.

We really need to get the codec->addr value, because that's used in hda_reg_read.

Recompiling to get this value...

Result is that codec->addr is 0x0, so not an issue.

At this point, reg is still 0x1d80c00. 

# 2023-07-27-08-33

So if reg were 0x1d30c00 instead of 0x1d80c00, then when hdac_reg_read calls is_stereo_amp_verb, it'll return back True, which would mean, in short, these pin cfgs are bit values of variables...

So, I've been thinking that it's the first bit that sets what the item is, but it's not. It's the third bit. Match the third bit in the config with the device types enum in hda_verbs, and that's what's assigned there.

0x90a00070 <- a is for mics, so this is somehow a mic.

0x90100010 <- 1 is for speakers, so this is a speaker. 

So, [here's the whole details on intel's site...](https://www.intel.com/content/dam/www/public/us/en/documents/product-specifications/high-definition-audio-specification.pdf)

(From the right)

* Bits 3-0 - Sequence
* Bits 7-4 - Default Association
* Bits 11-8 - Misc
* Bits 15-12 - Color
* Bits 19-16 - Connection Type
* Bits 23-20 - Default device
* Bits 29-24 - Location
  * 29-28 are the gross location (external, internal, other)
  * 27-24 are the geometric location (front, left, etc)
* Bits 31-30 - Port Connectivity

So a leading 4 would mean that it's an unconnected device with a location of "other"... most likely ignored. 

A leading 9 (b1000) would be a fixed function device (a speaker, maybe). 

Default device (4 bits) - Shows what the thing is. This corresponds to the device type enum in the hda_verbs.h file. 

Default association and sequence are used to group pin complexes together to support multichannel operations

So, looking at the hex code layout:

* Pos 1: Port connectivity & Gross Location
* Pos 2: Geometric location
* Pos 3: Default Device
* Pos 4: Connection Type
* Pos 5: Color
* Pos 6: Misc
* Pos 7: Default Association
* Pos 8: Sequence

So when the output from the headphones stopped working in Leif Liddy's mapping of NID 0x10, he changed bit 2 from 0x0 to 0x4, which only changed the geometric location from None to left, which probably did nothing. Bit 5 was changed from 4 to 2, which only changed the color from Green to Gray, but bit 7 was changed from 2 to f, which switched the association group. THis most likely caused a problem. 

I'm going to change bit 7 on the pin config on 0x10 back from f to 2, and reapply the pins to see what that does. I'm curious if the headphones will start working again with the windows pin configs posted [here](https://bugzilla.kernel.org/show_bug.cgi?id=110561#c40). Alsa-info incoming...

Headphones are working again. 

# 2023-07-27-08-38

Actually, false positive. There was an error in the build. Adding a semicolon and trying again.

Headphones still work.

# 2023-07-27-08-41

Putting back f in place of 2 and see what happens.

Headphones still work. Association group doesn't seem to matter. 

With the earlier situation, it seems that the verbs were really the issue. 

# 2023-07-27-08-49 

Going to try his tack of moving the speaker to 0x12.

Headphones still work. No speaker sound. 

# 2023-07-27-08-57

Changing 0x12 bit 3 from 1 to 4. (Speaker to S/PDIF)

Don't have much hope here, but we'll see. 

No real change here other than the S/PDIF changing. 

# 2023-07-27-09-46

Reading the INF file

    HKR,PinConfigOverrideVerbs,0002, 0x1,2b,1e,07,01	; HP: DD=HP, CTYP=combo

    HKR,PinConfigOverrideVerbs,0032, 0x1,50,1c,87,01	; HS: ASSN=5h, SEQ=0h			*
    HKR,PinConfigOverrideVerbs,0033, 0x1,20,1d,87,01	; HS: COL=gray				*
    HKR,PinConfigOverrideVerbs,0034, 0x1,ab,1e,87,01	; HS: DD=MI, CTYP=combo
    HKR,PinConfigOverrideVerbs,0035, 0x1,03,1f,87,01	; HS: PCON=jack, LOC=prim/left

So when looking at this, the 0002 in the first line is the 0-based decimal location of the pin. Let's say that we have this in the stack...

	static const struct hda_pintbl hda_pintbl_mb81_pincfgs_windows[] = {
		{ 0x10, 0x042b20f0 },  //stereo amp-out        #HP jack
		{ 0x11, 0x500000f0 },  //stereo
		{ 0x12, 0x90400010 },  //stereo  			   # speaker
		{ 0x13, 0x500000f0 },  //stereo
		{ 0x14, 0x500000f0 },  //stereo
		{ 0x15, 0x770000f0 },  //stereo Amp-In
		{ 0x16, 0x770000f0 },  //stereo Amp-In
		{ 0x17, 0x430000f0 },  //stereo Amp-In
		{ 0x18, 0x04ab2050 },  //mono Amp-In          #Mic Jack
		{ 0x19, 0x90a00070 },  //stereo Amp-In        #internal Mic
		{ 0x1a, 0x770000f0 },  //stereo Amp-In        
		{ 0x1b, 0x770000f0 },  //stereo Amp-In
		{ 0x1c, 0x770000f0 },  //stereo Amp-In
		{ 0x1d, 0x500000f0 },  //8-Channels Digital
		{ 0x1e, 0x500000f0 },  //8-Channels Digital
		{ 0x1f, 0x500000f0 },  //8-Channels Digital
		{ 0x20, 0x500000f0 },  //8-Channels Digital
		{ 0x21, 0x430000f0 },  //stereo digital
		{ 0x22, 0x430000f0 },  //stereo digital
		{} // Terminator
	};

The first line of the INF changes the third bit (which is the last 3rd and 4th digits of the first line in the hda_pintbl struct above) to 2b. 

So, looking at the pin configs in the second block above, count the numbers from right to left in sets of 2, starting with 0. So to show the numbers...

    0000 - f0
    0001 - 20
    0002 - 2b
    0003 - 04
    (next line)
    0004 - f0
    0005 - 00
    0006 - 00
    0007 - 50
    (third line)
    0008 - 10
    (et cetera)

I'm not quite sure what the third and fourth set of hex values are in the inf, but this clears up setting some of the pins. The windows pins don't really work as is, but it's a starting point.

Applying these gives us the pin configs of the following:

	static const struct hda_pintbl hda_pintbl_mb81_pincfgs_windows[] = {
		{ 0x10, 0x032b20f0 },  //0000 stereo amp-out        #HP jack
		{ 0x11, 0x500000f0 },  //0004 stereo
		{ 0x12, 0x500000f0 },  //0008 stereo  			   
		{ 0x13, 0x500000f0 },  //0012 stereo
		{ 0x14, 0x500000f0 },  //0016 stereo
		{ 0x15, 0x770000f0 },  //0020 stereo Amp-In
		{ 0x16, 0x770000f0 },  //0024 stereo Amp-In
		{ 0x17, 0x430000f0 },  //0028 stereo Amp-In
		{ 0x18, 0x03ab2050 },  //0032 mono Amp-In          #Mic Jack
		{ 0x19, 0x90a00070 },  //0036 stereo Amp-In        #internal Mic
		{ 0x1a, 0x770000f0 },  //0040 stereo Amp-In        
		{ 0x1b, 0x770000f0 },  //0044 stereo Amp-In
		{ 0x1c, 0x770000f0 },  //0048 stereo Amp-In
		{ 0x1d, 0x90400010 },  //0052 8-Channels Digital   # speaker
		{ 0x1e, 0x500000f0 },  //0056 8-Channels Digital
		{ 0x1f, 0x500000f0 },  //0060 8-Channels Digital
		{ 0x20, 0x500000f0 },  //0064 8-Channels Digital
		{ 0x21, 0x430000f0 },  //0068 stereo digital
		{ 0x22, 0x430000f0 },  //0072 stereo digital
		{} // Terminator
	};

Testing this out to see how it goes...

Headphones still work... Input still works, but no real change otherwise. Speakers still out. 

# 2023-07-27-10-02

Adding back in the verbs after a brief review.

Headphones broken. No sound. Input device gone. Everything broke.

# 2023-07-27-10-14

Commenting out a ton of verbs and trying again... May have to go through this in bits.

Still no sound. Still broken. 

# 2023-07-27-10-24

Still doesn't work. It's probably something with how I'm sending in the hda verbs. 

Trying a different structure. Probably won't work. 

Didn't work

# 2023-07-27-10-38

    snd_hda_sequence_write(codec, cs4208_coef_init_verbs_mb81);

Applying the sequence like this, which seems to correspond with how everyone else is doing it. We'll see. 

Headphones are working again, as is input, but speaker is still out. 

# 2023-07-27-10-46

There's a section of code around the proprobe that I am not really sure about. I'm commenting it out and trying again.

Seems to have done exactly nothing commenting it out. Still no speaker sound.

# 2023-07-27-13-20

Todo: need to implement the following lines from the InitVerbs section

    HKR,cs420x,n06AllowedInAmpIndex,%REG_BINARY%,	02		; ADC1: only allow SetAmpGain verbs with index=2

    HKR,cs420x,n0AWidgetCaps,	%REG_DWORD%,	0x00042631	; TX1: override widget caps: CCE=1
    HKR,cs420x,n0ASuppBitsRates,	%REG_DWORD%,	0x000E0040	; TX1: override rate caps: -R6

Also these GPIO settings: 

    [CONF_0807.Gpio]
    HKR,cs420x,Gpio0ExtAmpCfg,	%REG_BINARY%,	0A,00,00,01	; GPIO0 is an output controlled by TX1 PS-Set
    HKR,cs420x,Gpio4ExtAmpCfg,	%REG_BINARY%,	01,00,00,01	; GPIO4 is an output controlled by AFG PS-Set (to HS3 DFET)
    HKR,cs420x,Gpio5ExtAmpCfg,	%REG_BINARY%,	01,00,00,01	; GPIO5 is an output controlled by AFG PS-Set (to HS4 DFET)

There are also APO parameters which seem to be HPFs and LPFs on the speakers, but first, let's get some sound out. 

Models 0x7100 and 0x7200 seem to have some GPIO settings on them, as does the MacMini, which is 0x6c00. Looking in the INF files to compare the details there. 

7100 -> CONF_0800 -> Conf_0800.Gpio
7200 -> CONF_0801 -> Conf_0800.Gpio
6c00 -> CONF_0806 -> Conf_0806.Gpio

    [CONF_0800.Gpio]
    HKR,cs420x,Gpio0ExtAmpCfg,	%REG_BINARY%,	03,00,00,01	; GPIO0 is an output controlled by DAC2 PS-Set
    HKR,cs420x,Gpio4ExtAmpCfg,	%REG_BINARY%,	01,00,00,01	; GPIO4 is an output controlled by AFG PS-Set (to HS3/4 DFET)

    [CONF_0806.Gpio]
    HKR,cs420x,Gpio0ExtAmpCfg,	%REG_BINARY%,	03,00,00,01	; GPIO0 is an output controlled by DAC2 PS-Set

All three of these point to CS4208_GPIO0, which is in cs4208_fixup_gpio0. 

    static void cs4208_fixup_gpio0(struct hda_codec *codec,
                    const struct hda_fixup *fix, int action)
    {
        codec_info(codec, "Running gpio fixup");
        if (action == HDA_FIXUP_ACT_PRE_PROBE) {
            struct cs_spec *spec = codec->spec;

            spec->gpio_eapd_hp = 0;
            spec->gpio_eapd_speaker = 1;
            spec->gpio_mask = spec->gpio_dir =
                spec->gpio_eapd_hp | spec->gpio_eapd_speaker;
        }
    }

iMac27 uses the GPIO_13 setting... That's 0x106b, 0x2000. Is this in the inf? MBP81 and MBP55 also do... 1c00

Side note: additional pin config in cs4208_39.inf:

    HKR,PinConfigOverrideVerbs,0035, 0x1,01,1f,87,01	; HS: PCON=jack, LOC=prim/rear		*

iMac27_122 is an alias for GPIO_23...

Thinking that gpio_eapd_hp should be 1, because that is where the headphones are... in GPIO1. 

I think gpio_eapd_hp is a bit flag to apply to the IO stream, hence the mask. 

Right now the mask is all zeros.

    GPIO: io=6, o=2, i=0, unsolicited=1, wake=1
    IO[0]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[1]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[2]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[3]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[4]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[5]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0

When it was enabled before, it looked like this:

    GPIO: io=6, o=2, i=0, unsolicited=1, wake=1
    IO[0]: enable=1, dir=1, wake=0, sticky=0, data=0, unsol=0
    IO[1]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[2]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[3]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[4]: enable=1, dir=1, wake=0, sticky=0, data=0, unsol=0
    IO[5]: enable=1, dir=1, wake=0, sticky=0, data=0, unsol=0

That's because the enable is set to 0x31, which is 49, or b110001. 

The mask is right with 1, 4 and 5. It should be 0x31 or 49. 

Trying to assign the speaker to two GPIO ports. We'll see. 

No new news. Everything else is still working though.

# 2023-07-27-13-34

Interesting note from these two lines:

    04,00,45,02,  04,0C,44,02,\					; CIR=04h, coeff=0C04h (TX1 ch 0: slot  4, ch 1: slot 12)
    05,00,45,02,  00,10,44,02,\					; CIR=05h, coeff=1000h (TX1 ch 2: slot  0, ch 3: slot 16)

Based on this, this might be our two channels for TX1 ref'd in the verbs:

    [CONF_0807.Gpio]
    HKR,cs420x,Gpio0ExtAmpCfg,	%REG_BINARY%,	0A,00,00,01	; GPIO0 is an output controlled by TX1 PS-Set
    HKR,cs420x,Gpio4ExtAmpCfg,	%REG_BINARY%,	01,00,00,01	; GPIO4 is an output controlled by AFG PS-Set (to HS3 DFET)
    HKR,cs420x,Gpio5ExtAmpCfg,	%REG_BINARY%,	01,00,00,01	; GPIO5 is an output controlled by AFG PS-Set (to HS4 DFET)

So if that's the case, then there may be something to the 0xA setting above... A = b1010

In a zero based system, maybe this corresponds ot ch 1 and ch 3?

Breaking to shift to IO[0]. brb

Same overall state. 

# 2023-07-27-14-15

HS == Headset?

    HKR,cs420x,n06AllowedInAmpIndex,%REG_BINARY%,	02		; ADC1: only allow SetAmpGain verbs with index=2

    HKR,cs420x,n0AWidgetCaps,	%REG_DWORD%,	0x00042631	; TX1: override widget caps: CCE=1
    HKR,cs420x,n0ASuppBitsRates,	%REG_DWORD%,	0x000E0040	; TX1: override rate caps: -R6

cs4208_fix_amp_caps works with that firist line above?

    [SettingsAllIdlePowerdown]					; makes the codec always enter D3 when idle
    HKR,PowerSettings,PerformanceIdleTime, %REG_BINARY%, 2C, 00, 00, 00	; power down after 44 + 16 = 60 sec when on ext. power
    HKR,PowerSettings,ConservationIdleTime,%REG_BINARY%, 04, 00, 00, 00	; power down after  4 + 16 = 20 sec when on battery

D3 must be idle or off.

    HKR,cs420x,n0AWidgetCaps,	%REG_DWORD%,	0x00042631	; TX1: override widget caps: CCE=1

applies to this:

    Node 0x0a [Audio Output] wcaps 0x46631: 8-Channels Digital Stripe
        Control: name="IEC958 Playback Con Mask", index=0, device=0
        Control: name="IEC958 Playback Pro Mask", index=0, device=0
        Control: name="IEC958 Playback Default", index=0, device=0
        Control: name="IEC958 Playback Switch", index=0, device=0
        Control: name="IEC958 Default PCM Playback Switch", index=0, device=0
        Device: name="CS4208 Digital", type="SPDIF", device=1
        Converter: stream=0, channel=0
        Digital: Enabled Non-Copyright
        Digital category: 0x1
        IEC Coding Type: 0x0
        PCM:
            rates [0x60]: 44100 48000
            bits [0xe]: 16 20 24
            formats [0x1]: PCM
        Power states:  D0 D3 EPSS
        Power: setting=D3, actual=D3
        Delay: 4 samples

Take a look at the wcaps values. We need to figure out how to change that.

snd_hda_override_wcaps(codec, 0xa, 0x00042631);

Rebooting. 

Hrm... Wcaps value didn't change... wondering why...

Moving it to the end of the fixup sequence to see if that makes a difference.

Here we go.

Still no change

# 2023-07-27-14-23

Adding some logging.

It's changing, but not holding for some reason.

# 2023-07-27-14-32

Adding some logging to see what's going on. 

There's some new error about device having limited channels... interesting.... This is only from the 13-34 and 14-54 logs, though. 

# 2023-07-27-14-54

More logs. Trying to figure out why overriding wcaps isn't working. 

Kinda stumped. Gonna reach out to the community for more on this. 

# 2023-07-27-15-19

Commenting out the wcaps override for 0x18 to see if that does anything. It seems to maybe be applied to 0x17 in the alsa-info?

# 2023-07-27-15-57

Looks like this changed something, so gonna put it back.

# 2023-07-27-16-04

Alsa lies. 

Don't count on the wcaps values in Alsa because they don't seem to be reliable. Changing the wcaps directly *does* change the way the system reacts, but it won't reflect in the wcaps. 

Setting gpio_data to 0xA. 

# 2023-07-27-16-23

Still no-go.

Change the speaker to non-digital... let's see.

# 2023-07-27-17-01

Still no go

Bad. Putting it back.

# 2023-07-27-17-04

It's put back. 

After an aplay once or twice, it seems to fail. 

snd_hda_parse_pin_defcfg in hda_auto_parser.c seems to be where the output from alsa is getting it's speaker config data from. I'm going to try to solve that speaker output missing thing.

    [    7.310553] snd_hda_codec_cirrus hdaudioC0D0: autoconfig for CS4208: line_outs=1 (0x10/0x0/0x0/0x0/0x0) type:hp
    [    7.310556] snd_hda_codec_cirrus hdaudioC0D0:    speaker_outs=0 (0x0/0x0/0x0/0x0/0x0)
    [    7.310558] snd_hda_codec_cirrus hdaudioC0D0:    hp_outs=0 (0x0/0x0/0x0/0x0/0x0)
    [    7.310559] snd_hda_codec_cirrus hdaudioC0D0:    mono: mono_out=0x0
    [    7.310561] snd_hda_codec_cirrus hdaudioC0D0:    dig-out=0x1d/0x0
    [    7.310562] snd_hda_codec_cirrus hdaudioC0D0:    inputs:

I have a feeling that this should contain line outs to 1d and speaker outs to 1d as well. The question is: nodes or pins...

0x10 is the hp out for sure.

Shot in the dark: gonna try moving the speaker back to 0x12 again and see what that does. I'll make it analog. 

# 2023-07-28-06-53

Still no audio from the speakers.

Interestingly, this changed the output from genlevel to non-copyright. Speaker outs and line_outs is still the same. Putting this back.

Looking again at snd_hda_parse_pin_defcfg to see the logic on how it figures out the speaker pin.

It fetches from cfg->speaker_pins

Working in line 428 of hda_auto_parser trying to decide what's happening. Stopping for the moment.

# 2023-07-28-08-08

The case statement on line 262 of hda_auto_parser.c has the AC_JACK_SPEAKER enum check... Again, it's pulling from cfg->speaker_pins.

This case statement is never called... why?

dev should be set to AC_JACK_SPEAKER

    213 dev = get_defcfg_device(def_conf);

hda_local.c 370

    #define get_defcfg_device(cfg) \
	    ((cfg & AC_DEFCFG_DEVICE) >> AC_DEFCFG_DEVICE_SHIFT)  # 
    
hda_verbs.h 452

    #define AC_DEFCFG_DEVICE		(0xf<<20) # f00000
    #define AC_DEFCFG_DEVICE_SHIFT		20

Basically pulls the third bit in the defcfg value.

    0x01 = 0x2
    0x18 = 0xa
    0x19 = 0xa
    0x1d = 0x4

All others are 0.

Let's pop in another speaker into 0x12 and see what happens, leaving the digital one in place.

# 2023-07-28-08-22

Still no speaker sound, but a few things are different. In settings, we now have a speaker as well as an S/PDIF output. This is a change from the previous setup.

    [    4.726786] snd_hda_codec_cirrus hdaudioC0D0:    speaker_outs=0 (0x0/0x0/0x0/0x0/0x0)
    [    4.726789] snd_hda_codec_cirrus hdaudioC0D0:    hp_outs=1 (0x10/0x0/0x0/0x0/0x0)
    [    4.726793] snd_hda_codec_cirrus hdaudioC0D0:    mono: mono_out=0x0
    [    4.726795] snd_hda_codec_cirrus hdaudioC0D0:    dig-out=0x1d/0x0
    [    4.726798] snd_hda_codec_cirrus hdaudioC0D0:    inputs:

We still have no speaker_outs. I'm curious why. The AC JACK SPEAKER section is being called in the code. 

Adding some logging and rebooting.

# 2023-07-28-08-30

Obviously still no sound, but let's see what's changed.

We have this in the log now...

    [    5.364555] snd_hda_codec_cirrus hdaudioC0D0: SPEAKER pin: 12, seq: 10

More logs.

# 2023-07-28-08-35

    [    5.150754] snd_hda_codec_cirrus hdaudioC0D0: pre   speaker_outs=1 (0x0/0x0/0x0/0x0/0x0)
    [    5.150762] snd_hda_codec_cirrus hdaudioC0D0: Running the HDA_PINCFG_NO_LO_FIXUP
    [    5.150765] snd_hda_codec_cirrus hdaudioC0D0: autoconfig for CS4208: line_outs=1 (0x12/0x0/0x0/0x0/0x0) type:speaker
    [    5.150770] snd_hda_codec_cirrus hdaudioC0D0:    speaker_outs=0 (0x0/0x0/0x0/0x0/0x0)

Something is shutting down the speaker_outs in the HDA_PINCFG_NO_LO_FIXUP

Notable that the line_outs has changed to 0x12. 

Wondering if the speaker is really maybe 0x11 instead of 0x12. Changing to that.

# 2023-07-28-08-41

    [    5.206913] snd_hda_codec_cirrus hdaudioC0D0: pre   speaker_outs=1 (0x0/0x0/0x0/0x0/0x0)
    [    5.206918] snd_hda_codec_cirrus hdaudioC0D0: Running the HDA_PINCFG_NO_LO_FIXUP
    [    5.206920] snd_hda_codec_cirrus hdaudioC0D0: Found some speaker outs
    [    5.206922] snd_hda_codec_cirrus hdaudioC0D0: autoconfig for CS4208: line_outs=1 (0x11/0x0/0x0/0x0/0x0) type:speaker
    [    5.206928] snd_hda_codec_cirrus hdaudioC0D0:    speaker_outs=0 (0x0/0x0/0x0/0x0/0x0)
    [    5.206933] snd_hda_codec_cirrus hdaudioC0D0:    hp_outs=1 (0x10/0x0/0x0/0x0/0x0)
    [    5.206937] snd_hda_codec_cirrus hdaudioC0D0:    mono: mono_out=0x0
    [    5.206940] snd_hda_codec_cirrus hdaudioC0D0:    dig-out=0x1d/0x0
    [    5.206943] snd_hda_codec_cirrus hdaudioC0D0:    inputs:

So now I know how to get the line_outs set to what I want, but it's weird. 

Headphones are no longer working as of now. It seems that the line_outs has to contain the headphones. What we want is line_outs set to 0x10 and whatever the speaker is, with the speaker_outs also set to the speaker, but that seems to be getting slaughtered somewhere.

# 2023-07-28-08-47

    [    4.170639] snd_hda_codec_cirrus hdaudioC0D0: autoconfig for CS4208: line_outs=1 (0x10/0x0/0x0/0x0/0x0) type:hp
    [    4.170643] snd_hda_codec_cirrus hdaudioC0D0:    speaker_outs=0 (0x0/0x0/0x0/0x0/0x0)
    [    4.170646] snd_hda_codec_cirrus hdaudioC0D0:    hp_outs=0 (0x0/0x0/0x0/0x0/0x0)
    [    4.170649] snd_hda_codec_cirrus hdaudioC0D0:    mono: mono_out=0x0
    [    4.170651] snd_hda_codec_cirrus hdaudioC0D0:    dig-out=0x1d/0x0
    [    4.170654] snd_hda_codec_cirrus hdaudioC0D0:    inputs:

Line outs are still set to 0x11. Gonna see what happens when we remove the headphone jack and force the speaker, although I can't imagine that that would be that different. There apparently can only be one line_out... Gonna try the last configuration again. I might have gotten a false positive. The volume control beep wasn't working, but the test was. 


# 2023-07-28-08-52

    [    5.865393] snd_hda_codec_cirrus hdaudioC0D0: pre   speaker_outs=1 (0x0/0x0/0x0/0x0/0x0)
    [    5.865398] snd_hda_codec_cirrus hdaudioC0D0: Running the HDA_PINCFG_NO_LO_FIXUP
    [    5.865399] snd_hda_codec_cirrus hdaudioC0D0: Found some speaker outs
    [    5.865401] snd_hda_codec_cirrus hdaudioC0D0: autoconfig for CS4208: line_outs=1 (0x12/0x0/0x0/0x0/0x0) type:speaker
    [    5.865406] snd_hda_codec_cirrus hdaudioC0D0:    speaker_outs=0 (0x0/0x0/0x0/0x0/0x0)
    [    5.865409] snd_hda_codec_cirrus hdaudioC0D0:    hp_outs=1 (0x10/0x0/0x0/0x0/0x0)
    [    5.865412] snd_hda_codec_cirrus hdaudioC0D0:    mono: mono_out=0x0
    [    5.865414] snd_hda_codec_cirrus hdaudioC0D0:    dig-out=0x1d/0x0
    [    5.865416] snd_hda_codec_cirrus hdaudioC0D0:    inputs:

The speaker still doesn't work, but the line out does work. Wondering if I need to reset the sequence here?

	if (!cfg->line_outs &&
		!(cond_flags & HDA_PINCFG_NO_LO_FIXUP))
	{
		codec_info(codec, "Running the HDA_PINCFG_NO_LO_FIXUP");

So what is cond_flags?

It's being passed in directly...

    int snd_hda_parse_pin_defcfg(struct hda_codec *codec,
							 struct auto_pin_cfg *cfg,
							 const hda_nid_t *ignore_nids,
							 unsigned int cond_flags)

But it's modified here... in hda_auto_parser.c

	if (!snd_hda_get_int_hint(codec, "parser_flags", &i))
		cond_flags = i;

I'm wondering what that method is doing, and if that's our culprit. Rebooting again.

# 2023-07-28-09-07

No dice. There's nothing happening there.

Directly outputting the cond flags. Trying again.

