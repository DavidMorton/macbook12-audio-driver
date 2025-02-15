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
0002
So when looking at this, the  in the first line is the 0-based decimal location of the pin. Let's say that we have this in the stack...

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

# 2023-07-28-09-11

    [    5.442601] snd_hda_codec_cirrus hdaudioC0D0: cond_flags: 00000000

OMG. I'm too close to this right now. Good thing we're going to lunch downtown later to get my mind off of it. That's a statement to NOT do the pin fixup. Let's pass that value in. 

# 2023-07-28-09-16

    [    4.645973] snd_hda_codec_cirrus hdaudioC0D0: Entering the parse auto-config for 4208....
    [    4.645976] snd_hda_codec_cirrus hdaudioC0D0: cond_flags: 00000000

Something didn't work right here...

Had it in the wrong place. Moved and rebooting.

# 2023-07-28-09-22

    [    5.495046] snd_hda_codec_cirrus hdaudioC0D0: pre   speaker_outs=1 (0x0/0x0/0x0/0x0/0x0)
    [    5.495051] snd_hda_codec_cirrus hdaudioC0D0: autoconfig for CS4208: line_outs=0 (0x0/0x0/0x0/0x0/0x0) type:line
    [    5.495056] snd_hda_codec_cirrus hdaudioC0D0:    speaker_outs=1 (0x12/0x0/0x0/0x0/0x0)
    [    5.495059] snd_hda_codec_cirrus hdaudioC0D0:    hp_outs=1 (0x10/0x0/0x0/0x0/0x0)
    [    5.495063] snd_hda_codec_cirrus hdaudioC0D0:    mono: mono_out=0x0
    [    5.495065] snd_hda_codec_cirrus hdaudioC0D0:    dig-out=0x1d/0x0
    [    5.495068] snd_hda_codec_cirrus hdaudioC0D0:    inputs:

line_outs is zero, and speaker_outs is 1, and hp_outs = 1.

Headphones don't work anymore. So it seems that the dig-out and the line_outs are the only thing that works here...

So I thought that it was going to set the line_outs to 2 things, and the speaker_outs and hp_outs to nothing, but it looks like, instead, it eliminated all of them...

Putting this back. The line-out seems to be just line out, and not for speakers at all.

Now I'm wondering how I can get the speaker_outs value working with the line outs as well....

Rebooting for a clean alsa-info.

# 2023-07-28-09-35

Back to where we were before.

    [    7.079498] snd_hda_codec_cirrus hdaudioC0D0: pre   speaker_outs=1 (0x0/0x0/0x0/0x0/0x0)
    [    7.079501] snd_hda_codec_cirrus hdaudioC0D0: Running the HDA_PINCFG_NO_LO_FIXUP
    [    7.079503] snd_hda_codec_cirrus hdaudioC0D0: Found some speaker outs
    [    7.079505] snd_hda_codec_cirrus hdaudioC0D0: autoconfig for CS4208: line_outs=1 (0x12/0x0/0x0/0x0/0x0) type:speaker
    [    7.079508] snd_hda_codec_cirrus hdaudioC0D0:    speaker_outs=0 (0x0/0x0/0x0/0x0/0x0)
    [    7.079510] snd_hda_codec_cirrus hdaudioC0D0:    hp_outs=1 (0x10/0x0/0x0/0x0/0x0)
    [    7.079513] snd_hda_codec_cirrus hdaudioC0D0:    mono: mono_out=0x0
    [    7.079514] snd_hda_codec_cirrus hdaudioC0D0:    dig-out=0x1d/0x0
    [    7.079516] snd_hda_codec_cirrus hdaudioC0D0:    inputs:

Interesting that speaker_outs is showing 1 before the NO_LO_FIXUP, but then is showing 0 after, but the values for the pins are still 0x0.

    &spec->gen.autocfg from cs_parse_autoconfig in patch_cirrus.c. This is from codec->spec. Which maybe has no speaker pins...

Analysing the speaker_pin configs first before the call into the hda_auto_parser.c method.

# 2023-07-28-09-51

As suspected, speaker pins are set to 0 here. Is this a spec from the mfr?

Trying to manually set it...

# 2023-07-28-10-00

    [    5.186894] snd_hda_codec_cirrus hdaudioC0D0: pre   speaker_outs=1 (0x0/0x0/0x0/0x0/0x0)
    [    5.186899] snd_hda_codec_cirrus hdaudioC0D0: Running the HDA_PINCFG_NO_LO_FIXUP
    [    5.186901] snd_hda_codec_cirrus hdaudioC0D0: Found some speaker outs
    [    5.186903] snd_hda_codec_cirrus hdaudioC0D0: autoconfig for CS4208: line_outs=1 (0x12/0x0/0x0/0x0/0x0) type:speaker
    [    5.186908] snd_hda_codec_cirrus hdaudioC0D0:    speaker_outs=0 (0x0/0x0/0x0/0x0/0x0)
    [    5.186912] snd_hda_codec_cirrus hdaudioC0D0:    hp_outs=1 (0x10/0x0/0x0/0x0/0x0)
    [    5.186915] snd_hda_codec_cirrus hdaudioC0D0:    mono: mono_out=0x0
    [    5.186918] snd_hda_codec_cirrus hdaudioC0D0:    dig-out=0x1d/0x0
    [    5.186920] snd_hda_codec_cirrus hdaudioC0D0:    inputs:

Headphones working, but still no change... I might not be setting it right...

A bit of logging to figure out what's going on.

# 2023-07-28-10-06

    [    5.515618] snd_hda_codec_cirrus hdaudioC0D0: AC JACK SPEAKER
    [    5.515620] snd_hda_codec_cirrus hdaudioC0D0: 1 SPEAKER pin: 00, seq: 00
    [    5.515623] snd_hda_codec_cirrus hdaudioC0D0: 2 SPEAKER pin: 12, seq: 10

Speaker pin is being set here in AC JACK SPEAKER

# 2023-07-28-10-10

Speaker pins is moved to 1, but then the actual pin goes missing...

This is likely because of the no pin config...

What happens when we put that back...

# 2023-07-28-10-17

    [    5.759979] snd_hda_codec_cirrus hdaudioC0D0: pre   speaker_outs=1 (0x0/0x0/0x0/0x0/0x0)
    [    5.759984] snd_hda_codec_cirrus hdaudioC0D0: autoconfig for CS4208: line_outs=0 (0x0/0x0/0x0/0x0/0x0) type:line
    [    5.759989] snd_hda_codec_cirrus hdaudioC0D0:    speaker_outs=1 (0x12/0x0/0x0/0x0/0x0)
    [    5.759993] snd_hda_codec_cirrus hdaudioC0D0:    hp_outs=1 (0x10/0x0/0x0/0x0/0x0)
    [    5.759997] snd_hda_codec_cirrus hdaudioC0D0:    mono: mono_out=0x0
    [    5.760000] snd_hda_codec_cirrus hdaudioC0D0:    dig-out=0x1d/0x0
    [    5.760002] snd_hda_codec_cirrus hdaudioC0D0:    inputs:

Speaker is now settled in speaker_outs, but again, the line_outs is empty. Output devices are missing again.

No HP sound or device.
No Speaker sound or device.

# 2023-07-28-10-21

Okay, still nothing, but I should probably try the different speaker outs. 

    [    5.286411] snd_hda_codec_cirrus hdaudioC0D0: autoconfig for CS4208: line_outs=1 (0x12/0x0/0x0/0x0/0x0) type:speaker
    [    5.286416] snd_hda_codec_cirrus hdaudioC0D0:    speaker_outs=0 (0x0/0x0/0x0/0x0/0x0)
    [    5.286419] snd_hda_codec_cirrus hdaudioC0D0:    hp_outs=1 (0x10/0x0/0x0/0x0/0x0)
    [    5.286423] snd_hda_codec_cirrus hdaudioC0D0:    mono: mono_out=0x0
    [    5.286425] snd_hda_codec_cirrus hdaudioC0D0:    dig-out=0x1d/0x0
    [    5.286427] snd_hda_codec_cirrus hdaudioC0D0:    inputs:

Speaker still doesn't work, but maybe the wrong pin?  We'll play with it later.

HP sound & device
Input works
Speaker device, but no sound.

Swapping the last bit of the speaker from 1 to f. Curious what will happen.

# 2023-07-28-12-31

Headphones work just fine.

No speaker working.

Literally nothing else changed.

Moving from 0x12 to 0x11 for output.

Stumped. Same issue again. 

What is TX1 and AFG?

AFG is Audio Function Group

There's a pin config # verbs setting in the INF file that corresponds to the number of verbs listed, which is 76. 

We pass the verbs into snd_hda_sequence_write (both in hda_codec.c), which in turn passes it to snd_hda_codec_write (hda_codec.h), which copies core and sends to snd_hdac_codec_write (hdac_device.c) which passes to codec_write (hdac_device.c) which gets cmd from snd_hdac_make_cmd (hdac_device.c) and passes it into snd_hdac_exec_verb (hdac_device.c), and then if codec->exec_verb exists, it calls that, otherwise it calls snd_hdac_bus_exec_verb (hdac_bus.c) which calls snd_hdac_bus_exec_verb_unlocked (hdac_bus.c) and returns from there (after applying a mutex).

So, these terms are sent sequentially to the end. It's curious that we would do that, because these seem to be generally overrides. I'm wondering if this should be applied, and then the whole thing sent across. 

Randomly changing to group 3 for pin 0x12. Why not. didn't seem to make a difference anyways. 

Trying to set gpio data to sense only the headphones, but not the speakers...

# 2027-07-28-14-07

Headphones still work. What happens when I swap these around....

setting gpio_dir to 0x30, which should be 110000.

# 2023-07-28/14-14

S/PDIF audio is still the only thing. Headphones work. Mic works. No speakers.

# 2023-07-28/14-14

No change, no sound.

Putting in some of the 421x stuff into the 4208. There's some kind of weird digital muting happening here.

Interestingly, the stream count went to 1, when it's been consistently 0, I think. I have to check into that more.

    Converter: stream=1, channel=0

From the notes about GPIO Direction...

    Control is a bit field representing the configuration of the GPIO signals.  If a bit position is a 0, the 
    associated GPIO signal is configured as an input.  If the bit is set to a 1, the associated GPIO signal 
    is configured as an output. 

In one of the other patches, I noticed that the GPIO data in the cs_automute (I think it was in ca0132_alt_select_out_quirk_set) is being set alternately depending on whether the headphones are hooked up or not. I'm curious if that has something to do with the sound maybe going through the headphones, but not through the speakers.

0xA = 0x0010010. Another one of these sets the speaker to 0x8. 

eapd_speaker directs to the GPIO that applies... so, GPIO0 goes to 0x1, and GPIO1 goes to 0x2. 

    GPIO0 = 1
    GPIO1 = 2
    GPIO2 = 4
    GPIO3 = 8
    GPIO4 = 16
    GPIO5 = 32

So GPIO4&5 should be going to 48?

Trying this.

# 2023-07-28/17-50

No go, but no big change either. 

I need a proper init function here. 

cs_init passes the cs4208 coef init verbs, but not necessarily the ones that we need.

Beginning to restructure the whole code base to give the card it's own patch info and everything.

Temporarily pointing the patch ops to a custom version of the patch ops in the cs4208.

TODO: Put back if this doesn't work. 

# 2023-07-28/18-24

No change. This has only managed to disable the GPIO pins. Going to see why...

Fixing one small thing about the GPIO pins and restarting.

# 2023-07-28/18-37

Okay. GPIO fixed. Now, what's going on with that 0x0A in the INF file for the GPIO setting... I really feel like that's sorta important.

Headphones don't switch over now.

We weren't running the init_input_coef and init_digital_coef anymore.

Something is really broken now.... 

Taking data out of 0x30... Putting it on 0x31.

# 2023-07-28-18-50

Changing back to the old init to see what that does.

Headphones are back... Now why...

# 2023-07-28/19-03

Keeping the original method, but switching in the mb81 verbs instead...

# 2023-07-28/19-06

Headphones gone again. Our verbs are wrong somehow...

Changing VPW Processing to 0x01 from 0x02.

# 2023-07-28/19-10

Headphones back. Am I crazy? Trying again to set it off and see what happens...

I'm not... nevermind... not putting it back... The VPW flag should always have been 0x01. 

    01,03,47,02,\							; VPW: proc on

Still no speakers though. 

Let's write some more coef verbs!

# 2023-07-28/20-17

D0 is fully powered. D3 is shut down.

Might just be a power setting. 0x11-0x14 are simply shut down. There's no power with them at all. 

Power setting on 0xa is also off unless it's feeding the headphone jack.

Logging some automute behavior.

# 2023-07-28/20-46

Typo in codec_info so maybe that was a problem? Likely not, but still weird.

There were compile errors. Trying again.

# 2023-07-28/20-46

Even with build right, still not getting any results. There's something not running with the automute.

Adding more logging.

# 2023-07-28/21-07

So the automute hook is hooked, but not being called. What triggers it I wonder...

call_update_outputs from hda_generic.

More logs.

# 2023-07-28/21-15

    [    4.940991] snd_hda_codec_cirrus hdaudioC0D0: The automute hook is hooked in.
    [    4.940993] snd_hda_codec_cirrus hdaudioC0D0: automute_speaker: 00000000, detect_hp: 00000000, automute_lo: 00000000

They're all set to zeros.

This is why automuting isn't getting set.

Enabling headphone detection.

# 2023-07-28/21-19

Turning on automute speaker.

# 2023-07-28/21-24

The automute hook is working. Tomorrow to turn on the actual speakers. 

More logging.

# 2023-07-29

## 06-49

No SPDIF detected not continuing. 

Setting gen->spdif_detect to 1.

## 06-52

No spdif present.

What if I set all four speakers directly to the pin?

## 07-01

Speakers don't work. The side jack must be a line out. Still struggling with how to get the speakers_out set properly. 

The goal is is to be able to get line-out set to 0x10 and speaker out to 0x11, 0x12, 0x13x, 0x14. 

Manually setting speaker outs. 

## 07-15

Setting the line_outs manually. 

## 07-19

Headphones don't work anymore. 

Did something wrong. Fixing.

## 07-28

The speakers came up muted, which was interesting to me. Checking the log.

HDA_PINCFG_NO_LO_FIXUP is still being run, it shouldn't be. 

Setting the speaker pins and line out pins, but not the speaker_outs and line_outs, because that seems to be set later. 

## 07-37

Hrm. Now the speaker outs is set to 4, but there are none listed!

Lets change some pin sequences and see how that impacts things.

## 07-57 

Of course. memset resets the whole memory of an object. I think maybe I should skip this whole section and hardcode it?

We'll do that later.

Setting some bit flags to try to force the line out.

## 09-24

    [    4.290890] snd_hda_codec_cirrus hdaudioC0D0: autoconfig for CS4208: line_outs=1 (0x10/0x0/0x0/0x0/0x0) type:line
    [    4.290895] snd_hda_codec_cirrus hdaudioC0D0:    speaker_outs=4 (0x11/0x13/0x12/0x14/0x0)
    [    4.290899] snd_hda_codec_cirrus hdaudioC0D0:    hp_outs=0 (0x0/0x0/0x0/0x0/0x0)
    [    4.290903] snd_hda_codec_cirrus hdaudioC0D0:    mono: mono_out=0x0
    [    4.290905] snd_hda_codec_cirrus hdaudioC0D0:    dig-out=0x1d/0x0
    [    4.290908] snd_hda_codec_cirrus hdaudioC0D0:    inputs:

Got the speaker outs pinned now, and the line out is proper. Setting the pin to specifically be the line out seems to have done the trick. Speaker still doesn't play anything though.

We have *several* speakers listed in Alsamixer now.

Even so, power setting is still at D3, when it should be D0.

What's interesting is that only 0x10 and 0x11 have the Unsolicited flag. TODO: figure out what this unsolicited thing does.

How can I power on the speakers?

Turning off gen.automute_speakers will force data to go through all GPIO settings. I should see a 0x31 setting in the data, with 0, 4, and 5 all turned on. 

Trying that.

## 09-36

As expected, GPIO data is set to all three. 

Still no sound.

Power setting is still set to D3 for the speakers and for the 0x0a node. 

We should probably not even be playing with the LO at all. The headphones don't work anymore.

Setting the bit from 0 to 2 to turn 0x10 back into a headphone. Seeing if this turns the headphones back on again.

## 09-47

Headphones not on again. But there's clicking. 

Turning back on gen automute speakers...

## 09-51

Headphones still clicking but no sound.

No longer directly setting things... let's try again.

## 09-59

Argh. Lost headphones!

Looking back to comment some things out and try again.

Speaker is back, but not sure when that happened... the "Speaker" in the AlsaMixer was muted, and this caused the headphones to mute as well...

    ┌────────────────────────────── AlsaMixer v1.2.6 ──────────────────────────────┐
    │ Card: HDA Intel PCH                                  F1:  Help               │
    │ Chip: Cirrus Logic CS4208                            F2:  System information │
    │ View: F3:[Playback] F4: Capture  F5: All             F6:  Select sound card  │
    │ Item: Speaker [Off, Off]                             Esc: Exit               │
    │                                                                              │
    │     ┌──┐                       ┌──┐     ┌──┐     ┌──┐                        │
    │     │  │                       │▒▒│     │▒▒│     │  │                        │
    │     │  │                       │▒▒│     │▒▒│     │  │                        │
    │     │  │                       │▒▒│     │▒▒│     │  │                        →
    │     │▒▒│                       │▒▒│     │▒▒│     │  │                        →
    │     │▒▒│                       │▒▒│     │▒▒│     │  │                        →
    │     │▒▒│                       │▒▒│     │▒▒│     │  │                        →
    │     │▒▒│                       │▒▒│     │▒▒│     │  │                        →
    │     │▒▒│                       │▒▒│     │▒▒│     │  │                        →
    │     │▒▒│                       │▒▒│     │▒▒│     │  │                        →
    │     │▒▒│                       │▒▒│     │▒▒│     │  │                        │
    │     │▒▒│                       │▒▒│     │▒▒│     │  │                        │
    │     ├──┤     ┌──┐     ┌──┐     └──┘     └──┘     └──┘     ┌──┐     ┌──┐      │
    │     │OO│     │OO│     │MM│                                │MM│     │OO│      │
    │     └──┘     └──┘     └──┘                                └──┘     └──┘      │
    │      71                       97<>100 100<>100   0<>0                        │
    │    Master  Headphon<Speaker >  PCM    Line Out Mic Boos  S/PDIF  S/PDIF D    │
    └──────────────────────────────────────────────────────────────────────────────┘

Muting 0x11 effectively mutes the headphones as well.

Notes, muting the headphones mutes the master, but you can unmute the master and leave the headphones muted.

Muting speaker or headphones or master makes the headphones stop working.

0x11 must somehow be related to the headphones... a second channel on the headphones?

Maybe Leif was right, and the speaker is 0x12, and 0x11 is some kind of attachment to the headphones. 

Lets move around the speaker to 0x12 and see if muting that still mutes the headphones.

## 10-23
### HP+ S-

The speaker is moved to 0x12. The behavior is fixed. Muting the speaker no longer mutes the headphones, but we still don't have speaker sound, although we have headphone sound. 

Unsolicited is part of jack detection. 

Pin ctls for the headphone is 

    Pin-ctls: 0xc0: OUT HP (8+4=12 probably, with the 4 meaning "out" and the 12 meaning "HP")

And for the speaker (0x12) it's  0x40: OUT. So the 4 must mean "out"

This explains it:

    /* Pin widget control - 8bit */
    #define AC_PINCTL_EPT			(0x3<<0)
    #define AC_PINCTL_EPT_NATIVE		0
    #define AC_PINCTL_EPT_HBR		3
    #define AC_PINCTL_VREFEN		(0x7<<0)
    #define AC_PINCTL_VREF_HIZ		0	/* Hi-Z */
    #define AC_PINCTL_VREF_50		1	/* 50% */
    #define AC_PINCTL_VREF_GRD		2	/* ground */
    #define AC_PINCTL_VREF_80		4	/* 80% */
    #define AC_PINCTL_VREF_100		5	/* 100% */
    #define AC_PINCTL_IN_EN			(1<<5)
    #define AC_PINCTL_OUT_EN		(1<<6)
    #define AC_PINCTL_HP_EN			(1<<7)

So there's no specific thing for the speaker itself. It's just powered off!

0x12 is set to analog, but could it be digital?

What does the connection section mean?

    Connection: 1
     0x03

I'm beginning to think that the S/PDIF doesn't need to be touched at all...

Curious if this changes anything if I change 0x90100010 to 0x901000f0.

## 12-21, 12-25

Selecting the speakers node actually turned on the speaker, but I'm not sure why I'm still not hearing sound. 

    Node 0x12 [Pin Complex] wcaps 0x400501: Stereo
    Pincap 0x00000050: OUT Balanced
    Pin Default 0x90170011: [Fixed] Speaker at Int N/A
        Conn = Analog, Color = Unknown
        DefAssociation = 0x1, Sequence = 0x1
    Pin-ctls: 0x40: OUT
    Power states:  D0 D3 EPSS
    Power: setting=D0, actual=D0
    Connection: 1
        0x03

The only thing I'm thinking is maybe the speaker itself is digital? That seems somewhat strange to me, but the power setting has changed from D3 to D0, mhich means it's on... 

This again goes back to the question of the connection... what does the connection 0x03 mean?

Data on this is set to the following

    GPIO: io=6, o=2, i=0, unsolicited=1, wake=1
    IO[0]: enable=1, dir=1, wake=0, sticky=0, data=1, unsol=0
    IO[1]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[2]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[3]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[4]: enable=1, dir=1, wake=0, sticky=0, data=0, unsol=0
    IO[5]: enable=1, dir=1, wake=0, sticky=0, data=0, unsol=0

So it looks as though the data is set to 0x1 when it might need to be 0x30... what's setting that I wonder...

Adding some logging...

## 12-35

Moving gpio data to 4.

## 12-40

    GPIO: io=6, o=2, i=0, unsolicited=1, wake=1
    IO[0]: enable=1, dir=1, wake=0, sticky=0, data=1, unsol=0
    IO[1]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[2]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[3]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[4]: enable=1, dir=1, wake=0, sticky=0, data=1, unsol=0
    IO[5]: enable=1, dir=1, wake=0, sticky=0, data=0, unsol=0

Moving gpio speaker to 4 and 5. This should set IO[5] data to 1.

Not sure what is happening through IO[4] and IO[5] anyways. 

What is connection???

## 12-45
### HP+, S-

As expected...

    GPIO: io=6, o=2, i=0, unsolicited=1, wake=1
    IO[0]: enable=1, dir=1, wake=0, sticky=0, data=1, unsol=0
    IO[1]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[2]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[3]: enable=0, dir=0, wake=0, sticky=0, data=0, unsol=0
    IO[4]: enable=1, dir=1, wake=0, sticky=0, data=1, unsol=0
    IO[5]: enable=1, dir=1, wake=0, sticky=0, data=1, unsol=0

Lets move the speaker to a non-digital non-spdif at 0x1d, just as it apparently is in OS/X according to leif.

# 2023-07-30

## 07-29

Putting it back. That forced the headphones to be the output forever as there was no longer an actual speaker out listed.

## 2023-07-31

## 15-27

Wondering if 0x1e should maybe be another digital out...

Putting back the spdif.

## 15-35

This actually hooks up the values in Node 0x0a again. Wanna see what happens if I add another in there...

## 15-38

Changing from SPDIF to digital out other. Wondering if that'll fix somethings ....

## 15-47

### Windows VM research

Working through a VM install of Windows to try to grab the HDA verbs from the windows install. 

This is the device we're trying to install:

    00:1b.0 Audio device [0403]: Intel Corporation Wildcat Point-LP High Definition Audio Controller [8086:9ca0] (rev 03)

I've installed windows in qemu, and am about to install the windows support drivers for mac.

Following the work done [here](https://github.com/Conmanx360/QemuHDADump) with the QemuHDADump.

### Installing Samba

No real way to transfer files over to an emulator other than through an smb file share, so that's what I'm doing now. Installing Samba

With help from [this](https://www.techrepublic.com/article/share-directories-lan-from-ubuntu-desktop-22-04/) article, I was able to get the share working. 

Now that I've installed the Cirrus drivers on Windows, I'm getting sound from the Amplified Speakers in the list of devices!

Now to gather up the HDA Verbs.

Next Command:

    sudo ./start_vm.sh 2>&1 >/dev/null | ./QemuHDADump /dev/tty

Verbs are made like this:

    val = addr << 28; // address of the CORB buffer
    val |= (u32)nid << 20; // NID
    val |= verb << 8; // verb
    val |= parm; // verb parameter
    return val;

Flags gets set to zero

    snd_hda_codec_write(struct hda_codec *codec, hda_nid_t nid, int flags,
                unsigned int verb, unsigned int parm)
    {
        return snd_hdac_codec_write(&codec->core, nid, flags, verb, parm);
    }

	snd_hda_codec_write(codec, 0x12, 0, AC_VERB_SET_POWER_STATE, 0x00000003);

    #define AC_VERB_SET_POWER_STATE			0x705

So, ignoring codec address right now, because we don't know what that is...

nid = 0x12
flags = 0
verb = 0x705
parm = 0x3

001270503

In all corb frames, I found the pin setting code that the INF uses in Windows. It starts at offset 0x768

042b20f0
50170010
020410f0
02111010

# 2023-08-03

Updating some parameters from what I've seen with the CORB dump that I gathered. Going to retry with some limited changes and see what the result is.

First, I have to update grub again so that it allows the use of the PCI card.

## 07-35

## 07-55

Adding some logging to the codec writing.

## 08-09

Interestingly no logs for hda_codec.c.

## 08-14 

I think the first command is stopping the verbs from running.

## 08-30

Still no sound. 

Going back to do some research on how Windows was set up.

Okay, so the windows machine is set up with a device that is set as 8086 for the manufacturer, but the Cirrus device in the system is set with 1013, with 4208 as the manufacturer.

So we have: 8086:9ca0 in Windows according to the VM, but when installed against the bare metal, it's 1013:4208 with a subsystem of 106B6400.

VM: 8086:9CA0, Subsys: 72708086
Metal: 1013:4208, Subsys 106B6400

I'm thinking I might have been barking up the wrong tree this whole time... I think this may be a Wildcat and not a cirrus... so how are we getting to using the cirrus anyways?!

Nevermind. This is the same with leif's kernel. I have so much to learn here... what's the difference between the first thing and the second thing?

