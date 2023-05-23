-- База данных Словаря Шрилы Прабхупады SQLite

CREATE TABLE YAZYK (
    ID          INTEGER PRIMARY KEY,
    YAZYK       TEXT,
    YAZYK_SLOVO TEXT
);

CREATE TABLE SANSKRIT (
    ID          INTEGER PRIMARY KEY,
    IZNACHALYNO TEXT,
    PEREVOD     TEXT,
    YAZYK       TEXT,
    SSYLKI      TEXT
);

CREATE TABLE "UserReg"
(
    "UserRegKey" STRING(720) NOT NULL,
    "UserData" bytea,
    CONSTRAINT "UserReg_pkey" PRIMARY KEY ("UserRegKey")
);

-- База данных Словаря Шрилы Прабхупады PostgreSQL


