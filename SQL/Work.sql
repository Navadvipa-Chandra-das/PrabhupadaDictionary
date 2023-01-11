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
    "UserRegKey" character varying(720) NOT NULL,
    "UserData" bytea,
    CONSTRAINT "UserReg_pkey" PRIMARY KEY ("UserRegKey")
);

DROP TABLE "Languages";
CREATE TABLE "Languages"
(
    "LanguagesID" bigint PRIMARY KEY AUTOINCREMENT,
    "LanguagesStringID" character varying(5) NOT NULL,
    "Languages" character varying(32) NOT NULL,
    --CONSTRAINT "Languages_pkey" PRIMARY KEY ("LanguagesID")
);

DROP TABLE "LanguageKind";
CREATE TABLE "LanguageKind"
(
    "KindID" bigint AUTOINCREMENT,
    "ParentID" bigint,
    "Kind" character varying(100) NOT NULL,
    "Actual" boolean NOT NULL DEFAULT true,
    CONSTRAINT "LanguageKind_pkey" PRIMARY KEY ("KindID"),
    CONSTRAINT "LanguageKindParentFK" FOREIGN KEY ("ParentID")
        REFERENCES "LanguageKind" ("KindID") MATCH SIMPLE
        ON UPDATE CASCADE
        ON DELETE CASCADE
);

DROP TABLE "Language";
CREATE TABLE "Language"
(
    "EntityID" bigint AUTOINCREMENT,
    "KindID" bigint NOT NULL,
    "Entity" character varying(200) NOT NULL,
    "Actual" boolean NOT NULL DEFAULT true,
    "Original" text,
    CONSTRAINT "Language_pkey" PRIMARY KEY ("EntityID"),
    CONSTRAINT "LanguageKindID_Entity_UN" UNIQUE ("KindID", "Entity"),
    CONSTRAINT "LanguageKindFK" FOREIGN KEY ("KindID")
        REFERENCES "LanguageKind" ("KindID") MATCH SIMPLE
        ON UPDATE CASCADE
        ON DELETE CASCADE
);

CREATE TABLE "Translate"
(
    "TranslateID" bigint NOT NULL,
    "LanguageID" bigint NOT NULL,
    "LanguagesID" bigint NOT NULL,
    "Translate" text,
    CONSTRAINT "Translate_pkey" PRIMARY KEY ("TranslateID"),
    CONSTRAINT "LanguageFK" FOREIGN KEY ("LanguageID")
        REFERENCES "Language" ("EntityID") MATCH SIMPLE
        ON UPDATE CASCADE
        ON DELETE CASCADE,
    CONSTRAINT "LanguagesFK" FOREIGN KEY ("LanguagesID")
        REFERENCES "Languages" ("LanguagesID") MATCH SIMPLE
        ON UPDATE CASCADE
        ON DELETE CASCADE,
    CONSTRAINT "LanguagesCK" CHECK ("LanguagesID" > 1)
);

