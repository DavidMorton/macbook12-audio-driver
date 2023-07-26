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
## July 26, 2023

http://alsa-project.org/db/?f=ce64ed0d4758ad8c82729f65196d03f096854d22

Attempted to change the pin configs, but they never changed
http://alsa-project.org/db/?f=5130d3b650be85666ca7f635d9aa0abaf9938325

Removed the filter around setting the pins... previously this was checking to see if the HDA_FIXUP_ACT_PROBE was set for the action. Loads of weird driver pin configs are now appearing... I need to check that and figure out what's going on.
http://alsa-project.org/db/?f=a54c8639f40c063b95fecaa6d8f8ae4a94978710

After fixing some pin locations, the output is now saying it's "Digital Output (S/PDIF) - Built-in Audio" in the mixer in settings. This is a change. S/PDIF and S/PDIF Default PCM both lack volume controls in alsa-mixer. 
http://alsa-project.org/db/?f=e8c37be357e9991b2be1ee719bfdf97a8207ceea

Replaced the pin configuration with the one that came straight from Windows according to Leif Liddy's post. Internal mic still works, not much has changed otherwise. It seems that the label from 0x01 in the previous setup is now gone, and there's less detail in alsa-info than there was before about that node. 
http://alsa-project.org/db/?f=d611b443886d1122285a73bbc819791aacb03f00