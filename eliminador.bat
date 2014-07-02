@echo off
setlocal enabledelayedexpansion
title Eliminador de autorun.inf
echo Eliminador de autoruns v1.0

if "%1"=="" (
	:metodouno
	if exist autorun.inf (
		echo Intentando eliminar todos los autoruns existentes dentro de la ruta especificada
		
		attrib -r -s -h autorun.inf
		del /f /q autorun.inf
		
		if not exist autorun.inf (
			echo Autorun.inf borrado correctamente
		
		) else (
			echo Hubo un problema al borrar el autorun
		)
		
		goto fin
		
	) else (
		echo No se encontro ningun autorun.inf en el directorio:
		chdir
		goto fin
	)

) else (
	
	if "%2"=="" (
		
		cd %1
		goto metodouno
	
	) else (
		if "%2"=="/r" (
			rem Modo recursivo
			set /a flag = 0
			for /r %1 %%v in (*.inf) do (
				set /a flag = !flag! + 1
				goto sig
			)
			
			:sig
			if !flag! gtr 0 (
				cd %1
				attrib -r -s -h autorun.inf /s /d
				
				del *.inf /s /f /q
				goto fin
			
			) else (
				echo No se encontro ningun autorun.inf en el directorio:
				echo %1
				goto fin
			)
			
		) else (
			echo El segundo parametro debe ser /r para activar el modo recursivo
			goto fin
		)
	)
)

:fin
pause
