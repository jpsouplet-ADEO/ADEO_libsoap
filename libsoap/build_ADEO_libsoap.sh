#!/bin/bash
# Creation de la librairie libsoap, nanohttp

FILELOG="/tmp/ADEO_libsoap"
PATHRUN=$(dirname $0)

PATHSOAPADEO=/usr/local/soapadeo
PATHLIB="lib"

NBBITS=$(getconf LONG_BIT)
if [ $NBBITS -gt 32 ]
then
	PATHLIB=$PATHLIB"$NBBITS"
fi

# Preinstallation (On desinstalle la precedente version)
ISHERE=$(rpm -qa | grep ADEO_libsoap)
if [ "$ISHERE" != "" ]
then
	rpm -e $ISHERE
fi
	
# On se positionne dans le bon répertoire
cd $PATHRUN

# Configuration de l'environnement
echo "-------------------------------------------------------------" > $FILELOG
echo "  Configuration de l'environnement" >> $FILELOG
echo "-------------------------------------------------------------"
./configure --prefix=$PATHSOAPADEO --libdir=$PATHSOAPADEO/$PATHLIB --with-ssl >> $FILELOG 2>> $FILELOG
RETACT=$?
if [ $RETACT -eq 0 ]
then
	echo "-------------------------------------------------------------" >> $FILELOG
	echo "  Build" >> $FILELOG
	echo "-------------------------------------------------------------" >> $FILELOG
	make >> $FILELOG 2>> $FILELOG
	RETACT=$?
	if [ $RETACT -eq 0 ]
	then
		echo "-------------------------------------------------------------" >> $FILELOG
		echo "  Installation" >> $FILELOG
		echo "-------------------------------------------------------------" >> $FILELOG
		make install >> $FILELOG 2>> $FILELOG
		RETACT=$?
		if [ $RETACT -eq 0 ]
		then
			echo "-------------------------------------------------------------" >> $FILELOG
			echo "  Post Installation" >> $FILELOG
			echo "-------------------------------------------------------------" >> $FILELOG
			for MONLIENS in $(find /usr/include/ -maxdepth 1 -type d -name "libxml*")
			do 
				ln -s $MONLIENS /$PATHSOAPADEO/include/$(basename $MONLIENS)
			done
			
			for MONLIENS in $(find /usr/$PATHLIB/ -type l -name "libxml*")
			do 
				ln -s $MONLIENS /$PATHSOAPADEO/$PATHLIB/$(basename $MONLIENS)
			done
		fi
	fi
fi

if [ $RETACT -eq 0 ]
then
	mv -f "$FILELOG" "$FILELOG.log" 
else
	mv -f "$FILELOG" "$FILELOG.err"
fi
	
