# Elauthant

Elauthant stand as a Postgres extension designed to streamline authentication within your database instance without any biases.

## Why?

In my previous projects, I've grappled with authentication tools like Firebase and Supabase. Despite their assurances, especially Supabase, they ended up complicating the authentication process rather than simplifying it. This frustration led me to create Elauthant. My sole aim is straightforward: authentication within my database, free from unnecessary complications.

## How to run

### Clone

Recursive clone is needed to ensure that entire `vendor/postgres` is completely downloaded:

```bash
git clone --recursive https://github.com/J0sueTM/elauthant.git
```

### Configure

```bash
chmod +x configure
./configure
```

You can customize how `configure` generates the extension with the following ENVs and a couple of examples:

- **ELAUTHANT_VERSION**: 0.0.1, 1.3.4 (take a look at the tags)
- **ELAUTHANT_TARGET**: docker or host
- **ELAUTHENT_EXT_DIR**: `/usr/share/postgresql/15.5/extension`
- **PG_VERSION**: 15.5, 13.2
- **PG_USER**: admin
- **PG_PASSWORD**: my-strong-password
- **PG_DB**: my_db

An example configuration:

```bash
PG_USER=my_user PG_PASWORD=123456 ELAUTHENT_VERSION=0.0.01 ./configure
```

### Compile

If you don't have the `libpq` [previously installed](https://www.postgresql.org/docs/current/libpq.html), please compile PostgreSQL with:

```bash
cd vendor/postgres && make
```

```bash
make all
```

### Install

#### Host

If you configured elauthant to run on host, all you need to do is install the extension:

```bash
make install
```

#### Docker

If, instead, you configured elauthant to run on a docker container, you can either use my pre-made `docker-compose.yml`, and extend to your liking, or create your own image based on our env.

```bash
docker-compose up -d db
```

In case you want to create your own image, remember to copy the files:

- `elauthant--<your-version>.sql`
- `elauthant.control`
- `elauthant.[so|dylib|dll]`

Made with <3 by Josué Teodoro <teodoro.josue@pm.me>
