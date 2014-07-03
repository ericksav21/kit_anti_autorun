@echo off
setlocal enabledelayedexpansion
title Protector anti autorun.inf
echo Protector anti autorun.inf v1.0

if "%1"=="" (
	:init
	rem Si el usuario no ingresa la ruta
	echo Creando archivos
	set /a cont = 0
	
	rem Creamos primero los archivos
	if not exist autorun.inf (
		md autorun.inf
		set /a cont = !cont!+1
		echo Autorun.inf creado
	) else (
		echo No se pudo crear "autorun.inf" porque ya existe
	)
	
	if not exist autorun.ini (
		md autorun.ini
		set /a cont = !cont!+1
		echo Autorun.ini creado
	) else (
		echo No se pudo crear "autorun.ini" porque ya existe
	)
	
	if not exist system (
		@echo off > system.txt
		ren system.txt system
		set /a cont = !cont!+1
		echo Archivo "system" creado
	) else (
		echo No se pudo crear "system" porque ya existe
	)
	
	if not exist drive (
		@echo off > drive.txt
		ren drive.txt drive
		set /a cont = !cont!+1
		echo Archivo "drive" creado
	) else (
		echo No se pudo crear "drive" porque ya existe
	)

	if !cont! gtr 0 (
		if !cont! gtr 1 (
			echo Archivos creados
		
		) else (
			echo Archivo creado
		)
	
	) else (
		echo No se pudieron crear los archivos por alguna razon
		goto fin
	)
	
	echo Ocultando archivos
	
	set /a cont2 = 0
	if exist autorun.inf (
		attrib +r +h autorun.inf
		set /a cont2 = !cont2! + 1
	)
	if exist autorun.ini (
		attrib +r +h autorun.ini
		set /a cont2 = !cont2! + 1
	)
	if exist system (
		attrib +r +h system
		set /a cont2 = !cont2! + 1
	)
	if exist drive (
		attrib +r +h drive
		set /a cont2 = !cont2! + 1
	)
	
	if !cont2! gtr 0 (
		if !cont2! gtr 1 (
			echo Archivos ocultados
		
		) else (
			echo Archivo ocultado
		)
	
	) else (
		echo No se pudieron ocultar los archivos por alguna razon
	)
	
	goto fin
	
) else (
	if exist %1 (
		cd %1
		goto init
	
	) else (
		echo La ruta especificada no existe o no es correcta
		goto fin
	)
)

:fin
echo.
pause
exit
