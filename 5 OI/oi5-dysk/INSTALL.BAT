@cls
@echo Kopiuje plik archiwum na twardy dysk ...
@copy .\olimp c:\olimp.exe
@pause
@c:
@cd \
@echo Rozpakowuje pliki do katalogu C:\OLIMP ...
@olimp.exe
@cls
@echo Gotowe.
@pause
