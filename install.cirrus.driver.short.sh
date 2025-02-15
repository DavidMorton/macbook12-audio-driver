#!/bin/bash

kernel_version=$(uname -r | cut -d '-' -f1)  #ie 5.2.7
major_version=$(echo $kernel_version | cut -d '.' -f1)
minor_version=$(echo $kernel_version | cut -d '.' -f2)
major_minor=${major_version}${minor_version}

build_dir='.build'
update_dir="/lib/modules/$(uname -r)/updates"
patch_dir='patch_cirrus'
hda_dir="$build_dir/hda-$kernel_version"
#hda_dir="$build_dir/linux-$major_version.$minor_version/sound/pci/hda"

#tar --strip-components=3 -xvf $build_dir/linux-$kernel_version.tar.xz linux-$kernel_version/sound/pci/hda --directory=build/
#mv hda $hda_dir
mv $hda_dir/Makefile $hda_dir/Makefile.orig
mv $hda_dir/patch_cirrus.c $hda_dir/patch_cirrus.c.orig
mv $hda_dir/hda_auto_parser.c $hda_dir/hda_auto_parser.c.orig
mv $hda_dir/hda_codec.c $hda_dir/hda_codec.c.orig
#cp $patch_dir/Makefile $patch_dir/hda_auto_parser.c $patch_dir/patch_cirrus.c $patch_dir/patch_cirrus_a1534_setup.h $patch_dir/patch_cirrus_a1534_pcm.h $hda_dir/
cp $patch_dir/Makefile $patch_dir/hda_codec.c $patch_dir/hda_auto_parser.c $patch_dir/patch_cirrus.c $hda_dir/

# if kernel version is < 5.6 then change
# timespec64 to timespec
# ktime_get_real_ts64 to getnstimeofday
if [ $major_minor -lt 56 ]; then
   sed -i 's/timespec64/timespec/' $hda_dir/patch_cirrus.c
   #sed -i 's/timespec64/timespec/' $hda_dir/patch_cirrus_a1534_pcm.h
   #sed -i 's/ktime_get_real_ts64/getnstimeofday/' $hda_dir/patch_cirrus_a1534_pcm.h
fi

cd $hda_dir
make
make install

echo -e "\ncontents of $update_dir"
ls -lA $update_dir

# modify /etc/pulse/daemon.conf
# ensure four channels are enabled: 'default-sample-channels = 4'

pulse_daemon_conf='/etc/pulse/daemon.conf'
[[ ! -f $pulse_daemon_conf ]] && exit

default_sample_channels=$(grep '^default-sample-channels.*$' $pulse_daemon_conf)

if [ -n "$default_sample_channels" ]; then
   if [[ "$default_sample_channels" != 'default-sample-channels = 4' ]]; then
	  echo -e "\nmodifying /etc/pulse/daemon.conf\ndefault-sample-channels = 4"
	  sed -i 's/^default-sample-channels.*$/default-sample-channels = 4/' $pulse_daemon_conf
	  killall pulseaudio &> /dev/null
   fi
else
	  echo -e "\nmodifying /etc/pulse/daemon.conf\ndefault-sample-channels = 4"
	  echo 'default-sample-channels = 4' >> $pulse_daemon_conf
	  killall pulseaudio &> /dev/null
fi