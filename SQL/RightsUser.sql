CREATE TEMP TABLE IF NOT EXISTS public."RightsUser"
(
    "RightIndex" bigint NOT NULL,
    "Value" bigint NOT NULL
)
TABLESPACE pg_default;

ALTER TABLE IF EXISTS public."RightsUser" OWNER to "Navadvipa Chandra das";

COMMENT ON TABLE public."RightsUser" IS 'Права пользователей!';

select * from "RightsUser";
